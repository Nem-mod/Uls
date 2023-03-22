#include "uls.h"

void mx_print_usage(char err) {
    mx_printstr("uls: illegal option -- ");
    mx_printchar(err);
    mx_printstr("\nusage: uls [-");
    mx_printstr(VALID_FLAGS);
    mx_printstr("] [file ...]\n");
}
