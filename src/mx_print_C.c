#include "uls.h"

void mx_print_C(t_ls** ls_array){
    int k = 0;
    while (ls_array[k]) {
        for (int i = 0; i < ls_array[k]->elements_count; i++) {
            mx_printstr(ls_array[k]->elements[i].name);
            mx_printchar('\t');
        }
        k++;
    }
}