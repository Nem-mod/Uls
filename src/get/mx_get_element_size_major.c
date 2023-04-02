#include "uls.h"

t_size* mx_get_element_size_major(char* tempPath) {
    t_size* size = malloc(sizeof(t_size));
    struct stat element_stat;

    lstat(tempPath, &element_stat);
    size->size = major(element_stat.st_rdev);
    size->short_size = mx_itoa(size->size);

    size->full_size = NULL;

    return size;
}
