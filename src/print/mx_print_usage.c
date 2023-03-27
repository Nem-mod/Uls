#include "uls.h"

void mx_print_usage(char err) {
    mx_printerr("uls: illegal option -- ");
    write(2, &err, 1);
    mx_printerr("\nusage: uls [-");
    mx_printerr(VALID_FLAGS);
    mx_printerr("] [file ...]\n");
}
