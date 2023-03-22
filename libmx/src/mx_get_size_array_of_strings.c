#include "libmx.h"

int mx_get_size_array_of_strings(char** arr) {
    int i = 0;
    while (arr[i] != NULL) {
        i++;
    }
    return i;
}
