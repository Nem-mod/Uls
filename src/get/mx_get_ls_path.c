#include "uls.h"

char* mx_get_ls_path(char* name) {
    char* temp;
    char* path;

    // mx_printstr("HUI\n");
    // mx_strcat(str, name);
    // mx_printstr("HUI\n");
    temp = mx_strjoin("./", name);
    // mx_printstr("HUI\n");
    path = mx_strjoin(temp, "/");
    mx_strdel(&temp);
    // mx_printstr("HUI\n");

    return path;
}
