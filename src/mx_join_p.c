#include "uls.h"

void mx_join_p(t_shell* shell) {
    for (int i = 0; i < shell->ls_count; i++){
        for (int j = 0; j < shell->ls_array[i]->elements_count; j++) {
            if (shell->ls_array[i]->elements[j]->permission[0] == 'd') {
                shell->ls_array[i]->elements[j]->name = mx_strjoin(shell->ls_array[i]->elements[j]->name, "/");
            }
        }
        
    }
}
