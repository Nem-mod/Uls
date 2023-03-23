#include "uls.h"

t_ls **mx_create_ls_array(int size, char** dirs) {
    t_ls** ls = malloc(sizeof(t_ls*) * size);
    int i;

    for (i = 0; i < size; i++)
        ls[i] = mx_create_ls(mx_strjoin("./", dirs[i]));

    return ls;
}
