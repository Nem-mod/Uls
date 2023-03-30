#include "uls.h"

void mx_free_shell(t_shell **shell) {
    free((*shell)->flags);
    mx_del_strarr(&(*shell)->dirs);

    for (int i = 0; i < (*shell)->ls_count; i++) {
        mx_free_ls(&(*shell)->ls_array[i]);
        // free((*shell)->ls_array[i]);
    }

    free((*shell)->ls_array);
    free((*shell));
    *shell = NULL;
}
