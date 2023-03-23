#include "uls.h"

void mx_print_C(t_shell* shell){
    t_ls** ls_array = shell->ls_array;

    for (int i = 0;  i < shell->ls_count; i++) {
        for (int k = 0; k < ls_array[i]->elements_count; k++) {
            if (!ls_array[i]->elements[k].isVisible)
                continue;
            mx_printstr(ls_array[i]->elements[k].name);
            mx_printchar('\t');
        }
        mx_printchar('\n');
    }
}
