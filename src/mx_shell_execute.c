#include "uls.h"

int mx_shell_execute(t_shell* shell) {
    
    if(shell->display_mode == DISPLAY_MODE_l) {
        mx_print_l(shell);
    }

    if(shell->display_mode == DISPLAY_MODE_C) {
        mx_print_C(shell);
    }

    return 0; 
}
