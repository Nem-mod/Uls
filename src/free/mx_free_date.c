#include "uls.h"

void mx_free_date(t_date **date) {
    mx_strdel(&(*date)->long_date);
    mx_strdel(&(*date)->short_date);
    free(*date);
    *date = NULL;
}
