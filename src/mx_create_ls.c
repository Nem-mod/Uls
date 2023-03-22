#include "uls.h"

t_ls* mx_create_ls(char* path) {
    t_ls* ls = malloc(sizeof(t_ls));
    int elements_count = 0;
    DIR* dir = opendir(path); 
    struct dirent* entry;

    ls->path = mx_strdup(path);
    do {                     // while do replace!!!!
        entry = readdir(dir);
        if (entry == NULL)
            break;
        elements_count++;
    } while (entry != NULL);
    
    ls->elements = malloc(sizeof(t_element) * elements_count);
    ls->elements_count = elements_count;
    closedir(dir);
    dir = opendir(path);

    for (int i = 0; i < elements_count; i++) {
        entry = readdir(dir);
        mx_set_element_info(&ls->elements[i], entry);
    }

    return ls;
}
