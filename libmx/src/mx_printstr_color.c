#include "libmx.h"

void mx_printstr_color(const char* s, const char* color) {
    if (color != NULL)
        mx_printstr(color);
        
    mx_printstr(s);

    if (color != NULL)
        mx_printstr(COLOR_WHITE);
} 
