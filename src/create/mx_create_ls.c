#include "uls.h"

t_ls* mx_create_ls(char* name, int visibility_mode){
    t_ls* ls = malloc(sizeof(t_ls));
    int elements_count = 0;
    DIR* dir = opendir(name); 
    struct dirent* entry;

    if (dir == NULL)
        return NULL;

    ls->name = mx_strdup(name);
    ls->path = mx_get_ls_path(name);

    entry = readdir(dir);
    while (entry != NULL) { 
        switch (visibility_mode)
        {
        case VISIBILITY_MODE_vis:
            if(entry->d_name[0] == '.') {
                entry = readdir(dir);
                continue;
            }
            break;
        
        case VISIBILITY_MODE_A:
            if(!mx_strcmp(entry->d_name, ".")
            || !mx_strcmp(entry->d_name, "..")){
                entry = readdir(dir);
                continue;

            }
            break;
        }
        elements_count++;
        entry = readdir(dir);
    }
    
    ls->elements = malloc(sizeof(t_element) * elements_count);
    ls->elements_count = elements_count;
    closedir(dir);
    dir = opendir(name);

    ls->max_len_name = 0;
    ls->total = 0;
    ls->max_element_size = NULL;
    ls->max_links = 0;
    for (int i = 0; i < elements_count;) {
        entry = readdir(dir);
        switch (visibility_mode)
        {
        case VISIBILITY_MODE_vis:
            if(entry->d_name[0] == '.')
                continue;
            break;
        
        case VISIBILITY_MODE_A:
            if(!mx_strcmp(entry->d_name, ".")
            || !mx_strcmp(entry->d_name, ".."))
                continue;
            break;
        }
        mx_set_element_info(ls, &ls->elements[i], entry);

        
        if(ls->max_len_name < mx_strlen(entry->d_name)) {
            ls->max_len_name = mx_strlen(entry->d_name);
        }

        if(ls->max_element_size == NULL) {
            ls->max_element_size = ls->elements[i].size;
        } else if(ls->max_element_size->size < ls->elements[i].size->size) {
            ls->max_element_size = ls->elements[i].size;
        }

        
        if(ls->max_links < (int)ls->elements[i].links) {
            ls->max_links  = ls->elements[i].links;
        }
        i++;
    }
    closedir(dir);
    
    return ls;
}
