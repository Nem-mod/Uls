#include "uls.h"

void mx_print_m(t_shell* shell) {
    t_ls** ls_array = shell->ls_array;

    for (int i = 0;  i < shell->ls_count; i++) {
        if (shell->ls_count != 1) {
            mx_printstr(ls_array[i]->name);
            mx_printstr(":\n");   
        }

        for (int k = 0; k < ls_array[i]->elements_count; k++) {
            
            mx_print_element_name(&ls_array[i]->elements[k], shell->flags->G);
            // mx_printstr_color(ls_array[i]->elements[k].name, ls_array[i]->elements[k].color);
            if (k + 1  < ls_array[i]->elements_count) {
                mx_printchar(',');
                mx_printchar(' ');
            }
        }
        if (i != shell->ls_count - 1)
            mx_printchar('\n');
        mx_printchar('\n');
    }
}
