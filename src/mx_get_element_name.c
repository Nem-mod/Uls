#include "uls.h"

char* mx_get_element_name(struct dirent* entry) {
    return mx_strdup(entry->d_name);
}
