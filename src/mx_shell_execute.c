#include "uls.h"

static void print_ls_by_display_mode(t_shell* shell) {
    if(shell->display_mode == DISPLAY_MODE_NONE && isatty(1) == 0) {
        mx_print_one_col(shell);
    }
    if(shell->display_mode == DISPLAY_MODE_l) {
        mx_print_l(shell, shell->display_time_mode);
    }

    if(shell->display_mode == DISPLAY_MODE_C 
        || (shell->display_mode == DISPLAY_MODE_NONE && isatty(1))) {
        mx_print_C(shell);
    }
    if(shell->display_mode == DISPLAY_MODE_1) {
        mx_print_one_col(shell);
    }
    
}

static void sort_ls(t_shell* shell) {
    if(shell->sort_mode == WITHOUT_SORT) {
        return;
    } 

    if(shell->sort_mode == SORT_BY_TIME && shell->display_time_mode == DISPLAY_TIME_MODE_DEFAULT) {
        mx_sort_by_time_t(shell);
    }

    if(shell->sort_mode == SORT_BY_TIME && shell->display_time_mode == DISPLAY_TIME_MODE_u) {
        mx_sort_by_time_u(shell);
    }

    if(shell->sort_mode == SORT_BY_TIME && shell->display_time_mode == DISPLAY_TIME_MODE_c) {
        mx_sort_by_time_c(shell);
    }
    if(shell->sort_mode == SORT_BY_SIZE) {
        mx_sort_by_Size(shell->ls_array);
    } 

    if(shell->sort_mode == SORT_DEFAULT) {
        mx_sort_default(shell->ls_array);
    }
    
}


int mx_shell_execute(t_shell* shell) {
    sort_ls(shell);
    print_ls_by_display_mode(shell);

    return 0; 
}
