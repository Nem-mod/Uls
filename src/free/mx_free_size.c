#include "uls.h"

void mx_free_size(t_size **size) {
    mx_strdel(&(*size)->short_size);
    mx_strdel(&(*size)->full_size);
    free(*size);
    *size = NULL;
}
