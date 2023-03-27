#include "uls.h"

nlink_t mx_get_element_links_number(struct stat* stat) {
    return stat->st_nlink;
}
