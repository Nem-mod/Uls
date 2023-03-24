#include "uls.h"

static void print_ls_by_display_mode(t_shell* shell) {
    if(shell->display_mode == DISPLAY_MODE_NONE && isatty(1) == 0) {
        mx_print_one_col(shell->ls_array);
    }
    if(shell->display_mode == DISPLAY_MODE_l) {
        mx_print_l(shell);
    }

    if(shell->display_mode == DISPLAY_MODE_C 
        || (shell->display_mode == DISPLAY_MODE_NONE && isatty(1))) {
        mx_print_C(shell);
    }
    if(shell->display_mode == DISPLAY_MODE_1) {
        mx_print_one_col(shell->ls_array);
    }
    
}



int mx_shell_execute(t_shell* shell) {
    
    print_ls_by_display_mode(shell);

    return 0; 
}
