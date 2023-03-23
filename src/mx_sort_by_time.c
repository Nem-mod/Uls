#include "uls.h"

int mx_sort_by_time_c(t_ls** ls_array) {
    for (int k = 0; ls_array[k]; k++) {
        int i, j;
        t_element temp;
        for (i = 0; i < ls_array[k]->elements_count - 1; i++) {
            for (j = 0; j < ls_array[k]->elements_count - i - 1; j++) {
                if (ls_array[k]->elements[j].status_date->int_sec_date < ls_array[k]->elements[j + 1].status_date->int_sec_date) {
                    temp = ls_array[k]->elements[j];
                    ls_array[k]->elements[j] = ls_array[k]->elements[j + 1];
                    ls_array[k]->elements[j + 1] = temp;
                }
            }
        }
    }
    return 0;
}

int mx_sort_by_time_t(t_ls** ls_array) {
    for (int k = 0; ls_array[k]; k++) {
        int i, j;
        t_element temp;
        for (i = 0; i < ls_array[k]->elements_count - 1; i++) {
            for (j = 0; j < ls_array[k]->elements_count - i - 1; j++) {
                if (ls_array[k]->elements[j].modify_date->int_sec_date < ls_array[k]->elements[j + 1].modify_date->int_sec_date) {
                    temp = ls_array[k]->elements[j];
                    ls_array[k]->elements[j] = ls_array[k]->elements[j + 1];
                    ls_array[k]->elements[j + 1] = temp;
                }
            }
        }
    }
    return 0;
}

int mx_sort_by_time_u(t_ls** ls_array) {
    for (int k = 0; ls_array[k]; k++) {
        int i, j;
        t_element temp;
        for (i = 0; i < ls_array[k]->elements_count - 1; i++) {
            for (j = 0; j < ls_array[k]->elements_count - i - 1; j++) {
                if (ls_array[k]->elements[j].access_date->int_sec_date < ls_array[k]->elements[j + 1].access_date->int_sec_date) {
                    temp = ls_array[k]->elements[j];
                    ls_array[k]->elements[j] = ls_array[k]->elements[j + 1];
                    ls_array[k]->elements[j + 1] = temp;
                }
            }
        }
    }
    return 0;
}
