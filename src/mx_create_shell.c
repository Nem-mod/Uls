#include "uls.h"

static int get_last_entry_of_display_mode(char* flags) {
    int mode = DISPLAY_MODE_NONE;
    for (int i = 0; i < mx_strlen(flags); i++) {
        if(flags[i] == 'l')
            mode = DISPLAY_MODE_l;
        if(flags[i] == '1')
            mode = DISPLAY_MODE_1;
        if(flags[i] == 'C')
            mode = DISPLAY_MODE_C;
    }
    return mode;
}

static int get_last_entry_of_display_time(char* flags) {
    int mode = DISPLAY_TIME_MODE_DEFAULT;
    for (int i = 0; i < mx_strlen(flags); i++) {
        if(flags[i] == 'u')
            mode = DISPLAY_TIME_MODE_u;
        if(flags[i] == 'c')
            mode = DISPLAY_TIME_MODE_c;
    }
    return mode;
}

static int get_sort_mode(char* flags) {
    int mode = SORT_DEFAULT;
    for (int i = 0; i < mx_strlen(flags); i++) {
        if(flags[i] == 't')
            mode = SORT_BY_TIME;
        if(flags[i] == 'S')
            mode = SORT_BY_SIZE;
        if(flags[i] == 'f')
            mode = WITHOUT_SORT;
    }
    return mode;
}

t_shell* mx_create_shell(int argc, char* argv[]) {
    t_shell* shell = malloc(sizeof(t_shell));
    int amount_of_dirs;
    
    shell->flags = mx_get_flags(argc, argv);
    shell->dirs = mx_get_dirs(argc, argv);
    amount_of_dirs = mx_get_size_array_of_strings(shell->dirs);
    shell->ls_count = amount_of_dirs;
    shell->ls_array = mx_create_ls_array(shell->ls_count, shell->dirs);
    shell->display_mode = get_last_entry_of_display_mode(shell->flags);
    shell->display_time_mode = get_last_entry_of_display_time(shell->flags);
    shell->sort_mode = get_sort_mode(shell->flags);
    return shell;
}
