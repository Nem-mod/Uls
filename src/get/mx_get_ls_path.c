#include "uls.h"

char* mx_get_ls_path(char* name) {
    char* temp;
    char* path;

    if(name[0] == '/' || name[0] == '.') {
        temp = mx_strdup(name);
        path = mx_strjoin(temp, "/");
        mx_strdel(&temp);
        
        return  path;
    }

    path = mx_strjoin(name, "/");

    return path;
}
