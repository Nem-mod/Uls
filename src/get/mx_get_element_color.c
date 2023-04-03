#include "uls.h"

char* mx_get_element_color(char* permission) {
    if (isatty(1)) {
        if (permission[0] == 'd')
            return mx_strdup(COLOR_BLUE);
        else if (permission[0] == 'l')
            return mx_strdup(COLOR_LIGHT_MAGENTA);
        else if (permission[3] == 'x')
            return mx_strdup(COLOR_RED);
        else
            return mx_strdup(COLOR_WHITE);
    }
            
    return NULL;
}
