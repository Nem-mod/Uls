#include "uls.h"

void mx_free_element(t_element **element) {
    if (*element == NULL)
        return;
    mx_strdel(&(*element)->name);
    mx_strdel(&(*element)->path);
    mx_strdel(&(*element)->link_to);
    mx_strdel(&(*element)->permission);
    mx_strdel(&(*element)->owner_name);
    mx_strdel(&(*element)->group_name);
    mx_strdel(&(*element)->color);
    mx_strdel(&(*element)->xattrs);
    mx_free_size(&(*element)->size);
    mx_free_size(&(*element)->size_major);
    mx_free_size(&(*element)->size_minor);
    mx_free_date(&(*element)->access_date);
    mx_free_date(&(*element)->modify_date);
    mx_free_date(&(*element)->status_date);
    free(*element);
    *element = NULL;
}
