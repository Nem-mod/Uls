#include "uls.h"

char* mx_get_element_path(t_ls* ls, struct dirent* entry) {
    return mx_strjoin(ls->path, entry->d_name);
}
