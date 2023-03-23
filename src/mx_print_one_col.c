#include "uls.h"

void mx_print_one_col(t_ls** ls_array) {
    int k = 0;
    while (ls_array[k]) {
        mx_printint(ls_array[k]->total);

        for (int i = 0; i < ls_array[k]->elements_count; i++) {
            if (!ls_array[k]->elements[i].isVisible)
                continue;
            mx_printstr(ls_array[k]->elements[i].name);
            mx_printchar('\n');
        }
        
        mx_printchar('\n');
        k++;
    }   
}
