#include "uls.h"

void mx_print_usage(char err) {
    mx_printerr("uls: illegal option -- ");
    mx_printerr(&err);
    mx_printerr("\nusage: uls [-");
    mx_printerr(VALID_FLAGS);
    mx_printerr("] [file ...]\n");
}
