#include "uls.h"

static int get_number_of_digits(int number){
    int i = 0;
    while (number >= 1) {
        i++;
        number = number / 10;
    }
    if (i == 0)
        i++;

    return i;
}

// TODO: free mx_itoa
void mx_print_l(t_shell* shell, int time_flag) {
    t_ls** ls_array = shell->ls_array;
    for (int i = 0;  i < shell->ls_count; i++) {
        if (shell->ls_count != 1) {
            mx_printstr(ls_array[i]->name);
            mx_printstr(":\n");   
        }
        int max_element_size_len = get_number_of_digits(shell->ls_array[i]->max_element_size->size);
        mx_printstr("total ");
        mx_printint(ls_array[i]->total);
        mx_printchar('\n');
    
        for (int k = 0; k < ls_array[i]->elements_count; k++) {
            mx_printstr(ls_array[i]->elements[k]->permission);
            mx_print_nspace(get_number_of_digits(ls_array[i]->max_links) - get_number_of_digits((int)ls_array[i]->elements[k]->links) +
                            2 - mx_strlen(ls_array[i]->elements[k]->permission) + 10);
            
            mx_printint(ls_array[i]->elements[k]->links);
            mx_print_nspace(1);

            mx_printstr(ls_array[i]->elements[k]->owner_name);
            mx_print_nspace(ls_array[i]->max_o_name - mx_strlen(ls_array[i]->elements[k]->owner_name) + 2);

            mx_printstr(ls_array[i]->elements[k]->group_name);
            mx_print_nspace(ls_array[i]->max_g_name - mx_strlen(ls_array[i]->elements[k]->group_name));
            if (ls_array[i]->max_major > 0)
                mx_print_nspace(get_number_of_digits(ls_array[i]->max_major) - get_number_of_digits(ls_array[i]->elements[k]->size_major->size) + 2);

            if (ls_array[i]->elements[k]->permission[0] == 'c' || ls_array[i]->elements[k]->permission[0] == 'b') {
                mx_printstr(ls_array[i]->elements[k]->size_major->short_size);
                mx_printstr(", ");
                if (ls_array[i]->elements[k]->size_minor->size < 256)
                    mx_print_nspace(get_number_of_digits(ls_array[i]->max_minor) - get_number_of_digits(ls_array[i]->elements[k]->size_minor->size));
                mx_printstr(ls_array[i]->elements[k]->size_minor->short_size);
                mx_print_nspace(1);
            } else {
                if (ls_array[i]->max_major > 0) {
                    mx_print_nspace(get_number_of_digits(ls_array[i]->max_minor) - max_element_size_len + 1);
                }
                mx_print_nspace(max_element_size_len - get_number_of_digits(shell->ls_array[i]->elements[k]->size->size) + 2);
                mx_printint(ls_array[i]->elements[k]->size->size);
                mx_print_nspace(1);
            }

            switch (time_flag) {
                case DISPLAY_TIME_MODE_DEFAULT:
                    if(shell->flags->T) 
                        mx_printstr(ls_array[i]->elements[k]->modify_date->long_date);
                    else 
                        mx_printstr(ls_array[i]->elements[k]->modify_date->short_date);
                    break;
                case DISPLAY_TIME_MODE_u:
                    if(shell->flags->T) 
                        mx_printstr(ls_array[i]->elements[k]->access_date->long_date);
                    else 
                        mx_printstr(ls_array[i]->elements[k]->access_date->short_date);
                    break;
                case DISPLAY_TIME_MODE_c:
                    if(shell->flags->T) 
                        mx_printstr(ls_array[i]->elements[k]->status_date->long_date);
                    else 
                        mx_printstr(ls_array[i]->elements[k]->status_date->short_date);
                    break;
            }
            mx_print_nspace(1);

            mx_print_element_name(ls_array[i]->elements[k], shell->flags->G);
            if (ls_array[i]->elements[k]->link_to != NULL) {
                mx_printstr(" -> ");
                mx_printstr(ls_array[i]->elements[k]->link_to);
            }
            mx_printchar('\n');
            if (shell->flags->dog && ls_array[i]->elements[k]->xattrs != NULL) {
                mx_printchar('\t');
                mx_printstr(ls_array[i]->elements[k]->xattrs);
                mx_printstr(" \n");
            }
        }

        if (i != shell->ls_count - 1)
            mx_printchar('\n');
    }
    
   
}
