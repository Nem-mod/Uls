#include "uls.h"

void mx_set_element_info(t_element* element, struct dirent* entry) {
    element->name = mx_get_element_name(entry);
}
