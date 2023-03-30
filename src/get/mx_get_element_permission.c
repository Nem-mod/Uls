#include "uls.h"

char* mx_get_element_permission(struct stat* stat) {
    char* str = mx_strnew(11);
    mode_t mode = stat->st_mode;
    char* type = mx_get_element_type(mode);

    mx_strcat(str, type);
    mx_strcat(str, ((mode & S_IRUSR) ? "r" : "-"));
    mx_strcat(str, ((mode & S_IWUSR) ? "w" : "-"));
    mx_strcat(str, ((mode & S_IXUSR) ? "x" : "-"));
    mx_strcat(str, ((mode & S_IRGRP) ? "r" : "-"));
    mx_strcat(str, ((mode & S_IWGRP) ? "w" : "-"));
    mx_strcat(str, ((mode & S_IXGRP) ? "x" : "-"));
    mx_strcat(str, ((mode & S_IROTH) ? "r" : "-"));
    mx_strcat(str, ((mode & S_IWOTH) ? "w" : "-"));
    mx_strcat(str, ((mode & S_IXOTH) ? "x" : "-"));

    mx_strdel(&type);

    return str;
}
