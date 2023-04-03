#include "uls.h"

void mx_print_element_name(t_element* element, bool isColored) {
    if (isColored)
        mx_printstr_color(element->name, element->color);
    else
        mx_printstr_color(element->name, NULL);
}
