#include "libmx.h"

static int tolower(int c) {
    if (c >= 'A' && c <= 'Z') {
        return c + ('a' - 'A');
    } else {
        return c;
    }
}

char* mx_to_lower_case(char *str) {
    for (int i = 0; i < mx_strlen(str); i++) {
        str[i] = tolower(str[i]);
    }
    return str;
}
