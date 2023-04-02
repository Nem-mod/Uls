#include "uls.h"

t_date* mx_get_element_date(struct timespec* element_time) {
    time_t current_time; 
    t_date* date = malloc(sizeof(t_date));
    char* str_time = ctime(&element_time->tv_sec);
    char* year = mx_strndup(&str_time[20], 5);
    char* month = mx_strndup(&str_time[4], 4);
    char* day = mx_strndup(&str_time[8], 3);
    char* long_time = mx_strndup(&str_time[11], 9);
    
    year[4] = '\0';
    
    date->long_date = mx_strnew(21);
    mx_strcat(date->long_date, month);
    mx_strcat(date->long_date, day);
    mx_strcat(date->long_date, long_time);
    mx_strcat(date->long_date, year);

    time(&current_time);
    date->short_date = mx_strnew(21);
    mx_strcat(date->short_date, month);
    mx_strcat(date->short_date, day);
    if (current_time - element_time->tv_sec >= SIX_MONTH_SEC) {
        mx_strcat(date->short_date, " ");
        mx_strcat(date->short_date, year);
    } else {
        mx_strncat(date->short_date, long_time, 5);
    }

    date->int_sec_date = element_time->tv_sec;
    date->int_nanosec_date = element_time->tv_nsec;

    mx_strdel(&year);
    mx_strdel(&month);
    mx_strdel(&day);
    mx_strdel(&long_time);


    return date;
}
