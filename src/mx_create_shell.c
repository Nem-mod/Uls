#include "uls.h"

static int get_last_entry_of_display_mode(char* flags) {
    int mode = DISPLAY_MODE_C;
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

t_shell* mx_create_shell(int argc, char* argv[]) {
    t_shell* shell = malloc(sizeof(t_shell));
    
    shell->flags = mx_get_flags(argc, argv);
    shell->dirs = mx_get_dirs(argc, argv);
    int amount_of_dirs = mx_get_size_array_of_strings(shell->dirs);
    shell->ls_array = mx_create_ls_array(amount_of_dirs, shell->dirs);
    shell->display_mode = get_last_entry_of_display_mode(shell->flags);
    return shell;
}
