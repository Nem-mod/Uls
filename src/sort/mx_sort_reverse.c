#include "uls.h"

void mx_sort_reverse(t_shell* shell) {
    t_ls** ls_array = shell->ls_array;
    t_element* temp;

    for (int i = 0; i < shell->ls_count; i++) {
        for (int x = 0; x < ls_array[i]->elements_count / 2; x++) {
            temp = ls_array[i]->elements[x];
            ls_array[i]->elements[x] = ls_array[i]->elements[ls_array[i]->elements_count  - 1 - x];
            ls_array[i]->elements[ls_array[i]->elements_count  - 1 - x] = temp;
        }
    }
}
