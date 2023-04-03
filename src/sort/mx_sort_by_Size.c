#include "uls.h"

int mx_sort_by_Size(t_ls** ls_array) {
    for (int k = 0; ls_array[k]; k++) {
        int i, j;
        t_element* temp;
        for (i = 0; i < ls_array[k]->elements_count - 1; i++) {
            if (ls_array[k]->elements[i] == NULL)
                    continue;
            for (j = i + 1; j < ls_array[k]->elements_count; j++) {
                if (ls_array[k]->elements[j] == NULL)
                    continue;
                if (ls_array[k]->elements[i]->size->size < ls_array[k]->elements[j]->size->size || 
                    (ls_array[k]->elements[i]->size->size == ls_array[k]->elements[j]->size->size && 
                    mx_strcmp(ls_array[k]->elements[i]->name, ls_array[k]->elements[j]->name) > 0)) {
                    temp = ls_array[k]->elements[j];
                    ls_array[k]->elements[j] = ls_array[k]->elements[i];
                    ls_array[k]->elements[i] = temp;
                }
            }
        }
    }
    return 0;
}





