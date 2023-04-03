#include "uls.h"

static bool is_directory(const char *path) {
    struct stat statbuf;
   if (lstat(path, &statbuf) != 0)
        return 0;
    return S_ISDIR(statbuf.st_mode);
}

void mx_set_element_info(t_ls* ls, t_element** element, struct dirent* entry) {
    struct stat element_stat;
    struct passwd* user_info;
    struct group* group_info;
    char* temp;

    (*element)->name = mx_get_element_name(entry);
    (*element)->path = mx_get_element_path(ls, entry);

    if (lstat((*element)->path, &element_stat)) {
        temp = mx_strjoin("uls: ", (*element)->name);
        perror(temp);
        mx_strdel(&temp);

        mx_strdel(&(*element)->name);
        mx_strdel(&(*element)->path);
        free(*element);
        *element = NULL;

        return;
    }

    user_info = getpwuid(element_stat.st_uid);
    group_info = getgrgid(element_stat.st_gid);
    ls->total += element_stat.st_blocks;      

    (*element)->link_to = mx_get_element_name_link_to((*element)->path);
    (*element)->xattrs = mx_get_element_xattrs((*element)->path);
    (*element)->isAcl = mx_get_element_acl((*element)->path);
    (*element)->permission = mx_get_element_permission(&element_stat, (*element)->xattrs, (*element)->isAcl);
    (*element)->links = mx_get_element_links_number(&element_stat);
    (*element)->owner_name = mx_get_element_owner_name(user_info);
    (*element)->group_name = mx_get_element_group_name(group_info);
    (*element)->size = mx_get_element_size(&element_stat);
    (*element)->size_major = mx_get_element_size_major((*element)->path);
    (*element)->size_minor = mx_get_element_size_minor((*element)->path);
    (*element)->access_date = mx_get_element_date(&element_stat.st_atimespec);
    (*element)->modify_date = mx_get_element_date(&element_stat.st_mtimespec);
    (*element)->status_date = mx_get_element_date(&element_stat.st_ctimespec);
    (*element)->color = mx_get_element_color((*element)->permission);
    (*element)->is_dir = is_directory((*element)->path);
}
