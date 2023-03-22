#include "uls.h"

void mx_set_element_info(t_element* element, struct dirent* entry) {
    struct stat element_stat;
    struct passwd* user_info = getpwuid(element_stat.st_uid); // Add error handle 
    struct group* group_info = getgrgid(element_stat.st_gid); // Add error handle

    element->name = mx_get_element_name(entry);
    stat(element->name, &element_stat);     // Add error handle
    element->permission = mx_get_element_permission(&element_stat);
    element->links = mx_get_element_links_number(&element_stat);
    element->owner_name = mx_get_element_owner_name(user_info);
    element->group_name = mx_get_element_group_name(group_info);
    element->size = mx_get_element_size(&element_stat);
}
