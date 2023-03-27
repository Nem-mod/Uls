#include "uls.h"

void mx_print_one_col(t_shell* shell) {
    t_ls** ls_array = shell->ls_array;
    int k = 0;

    while (ls_array[k]) {
        if (shell->ls_count != 1) {
            mx_printstr(ls_array[k]->name);
            mx_printstr(":\n");   
        }
        for (int i = 0; i < ls_array[k]->elements_count; i++) {
            if (!ls_array[k]->elements[i].isVisible)
                continue;
            mx_printstr(ls_array[k]->elements[i].name);
            mx_printchar('\n');
        }        
        if (k != shell->ls_count - 1)
            mx_printchar('\n');
        k++;
    }   
}
