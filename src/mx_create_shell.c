#include "uls.h"

t_shell* mx_create_shell(int argc, char* argv[]) {
    t_shell* shell = malloc(sizeof(t_shell));
    shell->flags = mx_set_flags(argc, argv);
    shell->dirs = mx_set_dirs(argc, argv);

    return shell;
}
