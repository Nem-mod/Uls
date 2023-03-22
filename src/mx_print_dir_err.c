#include "uls.h"

void mx_print_dir_err(char* dir) {
    mx_printerr("ls: cannot access '");
    mx_printerr(dir);
    mx_printerr("': No such file or directory\n");
}
