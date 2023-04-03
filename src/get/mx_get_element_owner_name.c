#include "uls.h"

char* mx_get_element_owner_name(struct passwd* user_info) {
    return mx_strdup(user_info->pw_name);
}
