#include "uls.h"

char* mx_get_element_type(mode_t mode) {
    if (S_ISLNK(mode))
        return mx_strdup("l");
    if (S_ISDIR(mode))
        return mx_strdup("d");
    return mx_strdup("-");
}
