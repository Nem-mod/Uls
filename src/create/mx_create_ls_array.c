#include "uls.h"

t_ls **mx_create_ls_array(int size, char** dirs, int vivisibility_mode, char* flags) {
    t_ls** ls = malloc(sizeof(t_ls*) * size);
    int i;

    for (i = 0; i < size; i++)
        ls[i] = mx_create_ls(dirs[i], vivisibility_mode, flags);
    ls[i] = NULL;
    return ls;
}
