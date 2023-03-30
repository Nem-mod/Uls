#include "uls.h"

static bool is_directory(const char *path) {
   struct stat statbuf;
   if (stat(path, &statbuf) != 0)
       return 0;
   return S_ISDIR(statbuf.st_mode);
}

void mx_set_element_info(t_ls* ls, t_element* element, struct dirent* entry) {
    struct stat element_stat;
    struct passwd* user_info; // Add error handle 
    struct group* group_info; // Add error handle
    char* temp;

    element->name = mx_get_element_name(entry);
    element->path = mx_get_element_path(ls, entry);

    temp = mx_strjoin(ls->path, element->name);
    stat(temp, &element_stat);
    mx_strdel(&temp);

    user_info = getpwuid(element_stat.st_uid);
    group_info = getgrgid(element_stat.st_gid);
    ls->total += element_stat.st_blocks;      

    element->permission = mx_get_element_permission(&element_stat);
    element->links = mx_get_element_links_number(&element_stat);
    element->owner_name = mx_get_element_owner_name(user_info);
    element->group_name = mx_get_element_group_name(group_info);
    element->size = mx_get_element_size(&element_stat);
    element->access_date = mx_get_element_date(element_stat.st_atime);
    element->access_date->int_nanosec_date = element_stat.st_atime;
    element->modify_date = mx_get_element_date(element_stat.st_mtime);
    element->modify_date->int_nanosec_date = element_stat.st_mtime;
    element->status_date = mx_get_element_date(element_stat.st_ctime);
    element->status_date->int_nanosec_date = element_stat.st_ctime;
    element->color = mx_get_element_color(element->permission);
    element->is_dir = is_directory(element->path);
}
