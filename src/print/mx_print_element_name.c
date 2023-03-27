#include "uls.h"

void mx_print_element_name(t_element* el, bool isColored) {
    if (isColored) {
        if (el->permission[0] == 'd')
            mx_printstr_color(el->name, COLOR_BLUE);
        else if (el->permission[3] == 'x')
            mx_printstr_color(el->name, COLOR_RED);
        else
            mx_printstr_color(el->name, COLOR_WHITE);
    } else
        mx_printstr_color(el->name, COLOR_WHITE);       
}
