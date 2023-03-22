#include "uls.h"

t_shell* mx_create_shell(int argc, char* argv[]) {
    t_shell* shell = malloc(sizeof(t_shell));
    shell->flags = mx_get_flags(argc, argv);
    shell->dirs = mx_get_dirs(argc, argv);
    int amount_of_dirs = mx_get_size_array_of_strings(shell->dirs);
    shell->ls_array = mx_create_ls_array(amount_of_dirs, shell->dirs);
    return shell;
}
