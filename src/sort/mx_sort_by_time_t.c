#include "uls.h"

void mx_sort_by_time_t(t_shell* shell) {
    t_ls** ls_array = shell->ls_array;
    t_element* temp;
    t_date* first_date;
    t_date* second_date;

    for (int i = 0; i < shell->ls_count; i++) {
        for (int x = 0; x < ls_array[i]->elements_count - 1; x++) {
            if (ls_array[i]->elements[x] == NULL)
                    continue;
            for (int y = x + 1; y < ls_array[i]->elements_count; y++) {
                if (ls_array[i]->elements[y] == NULL)
                    continue;
                first_date = ls_array[i]->elements[x]->modify_date;
                second_date = ls_array[i]->elements[y]->modify_date;

                if (first_date->int_sec_date < second_date->int_sec_date ||
                    (first_date->int_sec_date == second_date->int_sec_date &&
                    first_date->int_nanosec_date < second_date->int_nanosec_date) ||
                    (first_date->int_sec_date == second_date->int_sec_date &&
                    first_date->int_nanosec_date == second_date->int_nanosec_date &&
                    mx_strcmp(ls_array[i]->elements[x]->name, ls_array[i]->elements[y]->name) > 0)) {
                        temp = ls_array[i]->elements[x];
                        ls_array[i]->elements[x] = ls_array[i]->elements[y];
                        ls_array[i]->elements[y] = temp;
                    }
            }
        }
    }
}
