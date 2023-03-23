#include "uls.h"

void mx_print_l(t_shell* shell) {
    t_ls** ls_array = shell->ls_array;
    for (int i = 0;  i < shell->ls_count; i++) {
        if (shell->ls_count != 1) {
            mx_printstr(ls_array[i]->name);
            mx_printstr(":\n");   
        }
    
        mx_printstr("total ");
        mx_printint(ls_array[i]->total);
        mx_printchar('\n');
    
        for (int k = 0; k < ls_array[i]->elements_count; k++) {
            if (!ls_array[i]->elements[k].isVisible)
                continue;
            mx_printstr(ls_array[i]->elements[k].permission);
            mx_printchar('\t');
            mx_printint(ls_array[i]->elements[k].links);
            mx_printchar('\t');
            mx_printstr(ls_array[i]->elements[k].owner_name);
            mx_printchar('\t');
            mx_printstr(ls_array[i]->elements[k].group_name);
            mx_printchar('\t');
            mx_printint(ls_array[i]->elements[k].size->size);
            mx_printchar('\t');
            mx_printstr(ls_array[i]->elements[k].modify_date->long_date);  // according to flags
            mx_printchar('\t');
            mx_printstr(ls_array[i]->elements[k].name);
            mx_printchar('\n');
            // printf("%ld | ", ls_array[i]->elements[k].modify_date->int_sec_date);  // according to flags
            // mx_printchar('\t');
            // printf("%ld | ", ls_array[i]->elements[k].modify_date->int_nanosec_date);  // according to flags
            // mx_printchar('\t');
            // printf("%s\n", ls_array[i]->elements[k].name);
        }

        if (i != shell->ls_count - 1)
            mx_printchar('\n');
    }
    
   
}
