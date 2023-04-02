#include "uls.h"

char* mx_get_element_name_link_to(char* path) {
    char* str = mx_strnew(MAX_LEN);
    
    if (readlink(path, str, MAX_LEN) < 0)
        return NULL;

    return str;
}
