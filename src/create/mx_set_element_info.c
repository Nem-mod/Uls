#include "uls.h"

static bool is_directory(const char *path) {
    struct stat statbuf;
   if (lstat(path, &statbuf) != 0)
        return 0;
    return S_ISDIR(statbuf.st_mode);
}

void mx_set_element_info(t_ls* ls, t_element* element, struct dirent* entry) {
    struct stat element_stat;
    struct passwd* user_info; // Add error handle 
    struct group* group_info; // Add error handle
    char* tempPath;

    element->name = mx_get_element_name(entry);
    element->path = mx_get_element_path(ls, entry);

    tempPath = mx_strjoin(ls->path, element->name);
    if (lstat(tempPath, &element_stat)) {
        perror("uls: ");
        element = NULL;
        return;
    }

    user_info = getpwuid(element_stat.st_uid);
    group_info = getgrgid(element_stat.st_gid);
    ls->total += element_stat.st_blocks;      

    // TODO: character block??????
    element->link_to = mx_get_element_name_link_to(element->path);
    element->xattrs = mx_get_element_xattrs(element->path);
    element->isAcl = mx_get_element_acl(element->path);
    element->permission = mx_get_element_permission(&element_stat, element->xattrs, element->isAcl);
    element->links = mx_get_element_links_number(&element_stat);
    element->owner_name = mx_get_element_owner_name(user_info);
    element->group_name = mx_get_element_group_name(group_info);
    element->size = mx_get_element_size(&element_stat);
    element->size_major = mx_get_element_size_major(tempPath);
    element->size_minor = mx_get_element_size_minor(tempPath);
    element->access_date = mx_get_element_date(&element_stat.st_atimespec);
    // element->access_date->int_nanosec_date = element_stat.st_atimespec.tv_nsec;
    element->modify_date = mx_get_element_date(&element_stat.st_mtimespec);
    // element->modify_date->int_nanosec_date = element_stat.st_mtimespec.tv_nsec;
    element->status_date = mx_get_element_date(&element_stat.st_ctimespec);
    // element->status_date->int_nanosec_date = element_stat.st_ctimespec.tv_nsec;
    element->color = mx_get_element_color(element->permission);
    element->is_dir = is_directory(element->path);

    mx_strdel(&tempPath);
}
