#include "libmx.h"

char* mx_hex_to_longhex(char* str) {
    char* longhex = mx_strnew(10);

    mx_strcat(longhex, "0x");
    for (int i = 0; i < 8 - mx_strlen(str); i++)
        mx_strcat(longhex, "0");
    mx_strcat(longhex, str);

    return longhex;
}
