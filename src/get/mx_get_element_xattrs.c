#include "uls.h"

char* mx_get_element_xattrs(char* path) {
    char* str = mx_strnew(MAX_LEN);
    int len;
    
    len = listxattr(path, str, MAX_LEN, XATTR_NOFOLLOW); 
    if (len <= 0)
        return NULL;

    for (int i = 0; i < len; i++) {
        if (str[i] == '\0')
            str[i] = '\t';
    }
    str[len] = '0';

    return str;
}
