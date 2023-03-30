#include "uls.h"

char* mx_get_element_type(mode_t mode) {
    if (S_ISDIR(mode))
        return mx_strdup("d");
    if (S_ISLNK(mode))
        return mx_strdup("l");
    if (S_ISBLK(mode))
        return mx_strdup("b");
    if (S_ISCHR(mode))
        return mx_strdup("c");
    if (S_ISSOCK(mode))
        return mx_strdup("s");
    if (S_ISFIFO(mode))
        return mx_strdup("p");
    return mx_strdup("-");
}
