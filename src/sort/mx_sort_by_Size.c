#include "uls.h"

int mx_sort_by_Size(t_ls** ls_array) {
    for (int k = 0; ls_array[k]; k++) {
        int i, j;
        t_element* temp;
        for (i = 0; i < ls_array[k]->elements_count - 1; i++) {
            for (j = 0; j < ls_array[k]->elements_count - i - 1; j++) {
                if (ls_array[k]->elements[j]->size->size < ls_array[k]->elements[j + 1]->size->size || 
                    (ls_array[k]->elements[j]->size->size == ls_array[k]->elements[j + 1]->size->size && 
                    mx_strcmp(ls_array[k]->elements[j]->name, ls_array[k]->elements[j + 1]->name) > 0)) {
                    temp = ls_array[k]->elements[j];
                    ls_array[k]->elements[j] = ls_array[k]->elements[j + 1];
                    ls_array[k]->elements[j + 1] = temp;
                }
            }
        }
    }
    return 0;
}





