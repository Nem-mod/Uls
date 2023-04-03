#include "uls.h"

char* mx_get_element_permission(struct stat* stat, char* xattrs, bool isAsl) {
    char* str = mx_strnew(13);
    mode_t mode = stat->st_mode;
    char* type = mx_get_element_type(mode);
    char* dog = mx_strdup("@");
    char* plus = mx_strdup("+");

    mx_strcat(str, type);
    mx_strcat(str, ((mode & S_IRUSR) ? "r" : "-"));
    mx_strcat(str, ((mode & S_IWUSR) ? "w" : "-"));
    mx_strcat(str, ((mode & S_IXUSR) ? "x" : "-"));
    mx_strcat(str, ((mode & S_IRGRP) ? "r" : "-"));
    mx_strcat(str, ((mode & S_IWGRP) ? "w" : "-"));
    mx_strcat(str, ((mode & S_IXGRP) ? "x" : "-"));
    mx_strcat(str, ((mode & S_IROTH) ? "r" : "-"));
    mx_strcat(str, ((mode & S_IWOTH) ? "w" : "-"));
    if ((mode & S_ISVTX))
        mx_strcat(str, "t");
    else if ((mode & S_IXOTH))
        mx_strcat(str, "x");
    else
        mx_strcat(str, "-");
    if (xattrs != NULL)
        mx_strcat(str, dog);
    else if (isAsl) 
        mx_strcat(str, plus);


    mx_strdel(&type);
    mx_strdel(&dog);
    mx_strdel(&plus);

    return str;
}
