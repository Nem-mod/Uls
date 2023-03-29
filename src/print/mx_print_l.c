#include "uls.h"

static int get_number_of_digits(int number){
    int i = 0;
    while (number >= 1) {
        i++;
        number = number / 10;
    }
    return i;
}

void mx_print_l(t_shell* shell, int time_flag) {
    t_ls** ls_array = shell->ls_array;
    for (int i = 0;  i < shell->ls_count; i++) {
        if (shell->ls_count != 1) {
            mx_printstr(ls_array[i]->name);
            mx_printstr(":\n");   
        }
        int max_element_size_len = mx_strlen(mx_itoa(shell->ls_array[i]->max_element_size->size));
        mx_printstr("total ");
        mx_printint(ls_array[i]->total);
        mx_printchar('\n');
    
        for (int k = 0; k < ls_array[i]->elements_count; k++) {
            mx_printstr(ls_array[i]->elements[k].permission);
            mx_print_nspace(get_number_of_digits(ls_array[i]->max_links) - get_number_of_digits((int)ls_array[i]->elements[k].links) + 2);
            
            mx_printint(ls_array[i]->elements[k].links);
            mx_print_nspace(1);

            mx_printstr(ls_array[i]->elements[k].owner_name);
            mx_print_nspace(2);

            mx_printstr(ls_array[i]->elements[k].group_name);
            mx_print_nspace(max_element_size_len - mx_strlen(mx_itoa(shell->ls_array[i]->elements[k].size->size)) + 2);

            mx_printint(ls_array[i]->elements[k].size->size);
            mx_print_nspace(1);

            switch (time_flag) { // according to flags
                case DISPLAY_TIME_MODE_DEFAULT:
                    if(shell->flags->T) 
                        mx_printstr(ls_array[i]->elements[k].modify_date->long_date);
                    else 
                        mx_printstr(ls_array[i]->elements[k].modify_date->short_date);
                    break;
                case DISPLAY_TIME_MODE_u:
                    if(shell->flags->T) 
                        mx_printstr(ls_array[i]->elements[k].access_date->long_date);
                    else 
                        mx_printstr(ls_array[i]->elements[k].access_date->short_date);
                    break;
                case DISPLAY_TIME_MODE_c:
                    if(shell->flags->T) 
                        mx_printstr(ls_array[i]->elements[k].status_date->long_date);
                    else 
                        mx_printstr(ls_array[i]->elements[k].status_date->short_date);
                    break;
            }
            mx_print_nspace(1);

            mx_print_element_name(&ls_array[i]->elements[k], shell->flags->G);
            // mx_printstr_color(ls_array[i]->elements[k].name, ls_array[i]->elements[k].color);
            mx_printchar('\n');
        }

        if (i != shell->ls_count - 1)
            mx_printchar('\n');
    }
    
   
}
