#include "uls.h"

t_date* mx_get_element_date(time_t element_time) {
    t_date* date = malloc(sizeof(t_date));
    // char* str_time = ctime(&element_time);
    

    date->long_date = ctime(&element_time);
    date->short_date = ctime(&element_time);

    return date;
}
