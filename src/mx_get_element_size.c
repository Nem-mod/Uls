#include "uls.h"

t_size* mx_get_element_size(struct stat* stat) {
    t_size* size = malloc(sizeof(t_size));

    size->size = stat->st_size;
    size->short_size = mx_itoa(size->size);

    // Implement full size (flag -h)
    size->full_size = NULL;

    return size;
}
