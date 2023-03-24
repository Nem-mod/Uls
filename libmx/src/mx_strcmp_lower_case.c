#include "libmx.h"

static int tolower(int c) {
    if (c >= 'A' && c <= 'Z') {
        return c + ('a' - 'A');
    } else {
        return c;
    }
}

int mx_strcmp_lower_case(const char *s1, const char *s2) {
    int char_count = 0;
    // int tempc1 = 0;
    // int tempc1 = 0;
    while (s1[char_count] != '\0' || s2[char_count] != '\0') {

        if (tolower(s1[char_count]) - tolower(s2[char_count]) != 0)
            return tolower(s1[char_count]) - tolower(s2[char_count]);
        char_count++;
    }
    return 0;
}
