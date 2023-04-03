#include "uls.h"

void mx_free_ls(t_ls **ls) {
    mx_strdel(&(*ls)->name);
    mx_strdel(&(*ls)->path);

    for (int i = 0; i < (*ls)->elements_count; i++)
        mx_free_element(&(*ls)->elements[i]);
    free((*ls)->elements);
    (*ls)->elements = NULL;

    free(*ls);
    *ls = NULL;
}
