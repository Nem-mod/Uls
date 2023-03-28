#include "uls.h"

char* mx_get_ls_path(char* name) {
    char* temp;
    char* path;

    if(name[0] == '/') {
        return  mx_strjoin(name, "/");
    }
    temp = mx_strjoin("./", name);
    path = mx_strjoin(temp, "/");
    mx_strdel(&temp);

    return path;
}
