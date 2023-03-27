#include "uls.h"

void mx_set_element_info(t_ls* ls, t_element* element, struct dirent* entry) {
    struct stat element_stat;
    struct passwd* user_info; // Add error handle 
    struct group* group_info; // Add error handle

    element->name = mx_get_element_name(entry);
    element->path = mx_get_element_path(ls, entry);

    stat(mx_strjoin(ls->path, element->name), &element_stat);     // Add error handle
    user_info = getpwuid(element_stat.st_uid);
    group_info = getgrgid(element_stat.st_gid);
    ls->total += element_stat.st_blocks;
    if (element->name[0] == '.')
        element->isVisible = false;
    else
        element->isVisible = true;       

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
}
