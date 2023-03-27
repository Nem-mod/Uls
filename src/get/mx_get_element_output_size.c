#include "uls.h"

char* mx_get_element_output_size(struct stat* stat) {
    return mx_itoa(stat->st_size);
}
