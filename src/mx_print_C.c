#include "uls.h"

void mx_print_C(t_shell* shell){
    t_ls** ls_array = shell->ls_array;

    for (int i = 0;  i < shell->ls_count; i++) {
        if (shell->ls_count != 1) {
            mx_printstr(ls_array[i]->name);
            mx_printstr(":\n");   
        }

        for (int k = 0; k < ls_array[i]->elements_count; k++) {
            if (!ls_array[i]->elements[k].isVisible)
                continue;
            mx_printstr(ls_array[i]->elements[k].name);
            mx_printchar('\t');
        }
        if (i != shell->ls_count - 1)
            mx_printchar('\n');
        mx_printchar('\n');
    }
}
