#include "uls.h"

t_date* mx_get_element_date(time_t element_time) {
    t_date* date = malloc(sizeof(t_date));
    char* str_time = ctime(&element_time);
    char* year = mx_strndup(&str_time[20], 5);
    char* month = mx_strndup(&str_time[4], 4);
    char* day = mx_strndup(&str_time[8], 3);
    char *long_time = mx_strndup(&str_time[11], 9);
    
    year[4] = ' ';
    // mx_printstr(year);
    // mx_printchar('|');
    // mx_printstr(month);
    // mx_printchar('|');
    // mx_printstr(day);
    // mx_printchar('|');
    // mx_printstr(long_time);
    // mx_printchar('|');
    // mx_printchar('\n');
    

    date->long_date = mx_strnew(21);
    mx_strcat(date->long_date, month);
    mx_strcat(date->long_date, day);
    mx_strcat(date->long_date, long_time);
    mx_strcat(date->long_date, year);

    date->short_date = mx_strndup(date->long_date, 12);

    return date;
}
