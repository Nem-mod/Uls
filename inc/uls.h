#pragma once

#include "libmx.h"

#include <stdio.h>
#include <dirent.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <pwd.h>
#include <grp.h>
#include <time.h>

// #define VALID_FLAGS "ACGRSTaclmrtu1"
#define VALID_FLAGS "Cl1"

#define DISPLAY_MODE_NONE 0
#define DISPLAY_MODE_C 1 
#define DISPLAY_MODE_1 2
#define DISPLAY_MODE_l 3

typedef struct s_date {

    char* long_date;
    char* short_date;

}               t_date;

typedef struct s_size {
    
    int size;
    char* short_size;
    char* full_size;

}               t_size;

typedef struct s_element {

    char* name;
    char* path;
    char* permission;
    nlink_t links;
    char* owner_name;
    char* group_name;
    t_size* size;
    t_date* access_date;
    t_date* modify_date;
    t_date* status_date;
    bool isVisible;

}               t_element;

typedef struct s_ls {
    
    char* path;
    // char* flags;
    int elements_count;
    t_element* elements;
    int total;

}               t_ls;

typedef struct s_shell {

    char* flags;
    char** dirs;
    t_ls** ls_array;
    int display_mode;

}              t_shell;

int mx_input_validation(int argc, char* argv[]);
void mx_print_usage(char err);
void mx_print_dir_err(char* dir);

void mx_add_flag(char* flags_string, char flag);

char* mx_get_flags(int argc, char* argv[]);
char** mx_get_dirs(int argc, char* argv[]);

t_shell* mx_create_shell(int argc, char* argv[]);

t_ls* mx_create_ls(char* path);
void mx_set_element_info(t_ls* ls, t_element* element, struct dirent* entry);
char* mx_get_element_name(struct dirent* entry);
char* mx_get_element_path(t_ls* ls, struct dirent* entry);
char* mx_get_element_permission(struct stat* stat);
nlink_t mx_get_element_links_number(struct stat* stat);
char* mx_get_element_owner_name(struct passwd* user_info);
char* mx_get_element_group_name(struct group* group_info);
t_size* mx_get_element_size(struct stat* stat);
t_date* mx_get_element_date(time_t element_time);

t_ls **mx_create_ls_array(int size, char** dirs);
// void mx_ls(t_shell* shell);

int mx_open_dir(t_shell* shell);

int mx_shell_execute(t_shell* shell);

// PRINT
void mx_print_l(t_ls** ls_array);
void mx_print_C(t_ls** ls_array);
void mx_print_one_col(t_ls** ls_array);


