#include "uls.h"

char* mx_get_element_group_name(struct group* group_info) {
    return mx_strdup(group_info->gr_name);
}
