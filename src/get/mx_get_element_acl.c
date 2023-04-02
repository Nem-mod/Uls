#include "uls.h"

bool mx_get_element_acl(char* path) {
    acl_t acl;
    bool isAsl = false;

    acl = acl_get_file(path, ACL_TYPE_EXTENDED);
    if (acl != NULL) {
        mx_printstr(path);
        mx_printchar('\n');
        isAsl = true;
    }
    acl_free(acl);

    return isAsl;
}
