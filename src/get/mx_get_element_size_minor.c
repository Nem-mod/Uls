#include "uls.h"

t_size* mx_get_element_size_minor(char* tempPath) {
    t_size* size = malloc(sizeof(t_size));
    struct stat element_stat;
    char* temp;

    lstat(tempPath, &element_stat);
    size->size = minor(element_stat.st_rdev);
    // size->size = ((int)((stat->st_rdev) & 0xff));
    // size->size = MINOR(stat->st_rdev);
    if (size->size < 256)
        size->short_size = mx_itoa(size->size);
    else {
        temp = mx_nbr_to_hex(size->size);
        size->short_size = mx_hex_to_longhex(temp);
        mx_strdel(&temp);
    }

    size->full_size = NULL;

    return size;
}
