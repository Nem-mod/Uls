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
#include <sys/ioctl.h>
#include <sys/xattr.h>
#include <sys/acl.h>

#define MAX_LEN 1024

// #define VALID_FLAGS "ACGRSTaclmrtu1"
#define VALID_FLAGS "ACGSTR@rlatucfmp1"

//  Display mode
#define DISPLAY_MODE_NONE 0
#define DISPLAY_MODE_C 1 
#define DISPLAY_MODE_1 2
#define DISPLAY_MODE_l 3
#define DISPLAY_MODE_m 5

//  Display time mode
#define DISPLAY_TIME_MODE_DEFAULT 0 
#define DISPLAY_TIME_MODE_c 1 
#define DISPLAY_TIME_MODE_u 2
#define SIX_MONTH_SEC 15778476

//  Sort mode
#define SORT_DEFAULT 0 
#define SORT_BY_SIZE 1 
#define SORT_BY_TIME 2
#define WITHOUT_SORT 3

//  Visuability mode (hidden elements)
#define VISIBILITY_MODE_a 0
#define VISIBILITY_MODE_A 1
#define VISIBILITY_MODE_vis 2

//  Output helpers
#define TWO_TABS 8

typedef struct s_date {

    char* long_date; // freed
    char* short_date; // freed
    time_t int_sec_date;
    long int_nanosec_date;

}               t_date;

typedef struct s_size {
    
    int size;
    char* short_size; // freed
    char* full_size; // freed

}               t_size;

typedef struct s_element {

    char* name; // freed
    char* path; // freed
    char* link_to; // freed
    char* xattrs; // freed
    bool isAcl;
    char* permission; // freed
    nlink_t links;
    char* owner_name; // freed
    char* group_name; // freed
    t_size* size; // freed
    t_size* size_major; // freed
    t_size* size_minor; // freed
    t_date* access_date; // freed
    t_date* modify_date; // freed
    t_date* status_date; // freed
    char* color; // freed
    bool is_dir;

}               t_element;

typedef struct s_ls {
    
    char* name; // freed
    char* path; // freed
    int elements_count;
    t_element** elements; // freed
    int total;
    int max_len_name;
    int max_links;
    int max_o_name;
    int max_g_name;
    int max_major;
    int max_minor;
    t_size* max_element_size;

}               t_ls;

typedef struct s_flags {
    
    bool A;
    bool C;
    bool G;
    bool S;
    bool l;
    bool a;
    bool t;
    bool u;
    bool c;
    bool f;
    bool m;
    bool p;
    bool one;
    bool T;
    bool r;
    bool R;
    bool dog;

}               t_flags;

typedef struct s_shell {

    t_flags* flags; // freed
    char** dirs; // freed
    int ls_count;
    t_ls** ls_array; // freed
    int display_mode;
    int display_time_mode;
    int sort_mode;
    int visibility_mode;

}              t_shell;

//  ==Create==
t_shell* mx_create_shell(t_flags* flags, char** dirs);
t_ls* mx_create_ls(char* name, int visibility_mode);
void mx_add_flag(t_flags* flags, char flag);
void mx_set_element_info(t_ls* ls, t_element** element, struct dirent* entry);
t_ls **mx_create_ls_array(int size, char** dirs, int vivisibility_mode);
t_flags* mx_init_empty_flags();


//  ==Get==
t_flags* mx_get_flags(int argc, char* argv[]);
char** mx_get_dirs(int argc, char* argv[]);
char* mx_get_ls_path(char* name);
char* mx_get_element_name(struct dirent* entry);
char* mx_get_element_path(t_ls* ls, struct dirent* entry);
char* mx_get_element_permission(struct stat* stat, char* xattrs, bool isAsl);
nlink_t mx_get_element_links_number(struct stat* stat);
char* mx_get_element_owner_name(struct passwd* user_info);
char* mx_get_element_group_name(struct group* group_info);
t_size* mx_get_element_size(struct stat* stat);
t_date* mx_get_element_date(struct timespec* element_time);
char* mx_get_element_color(char* permission);
char* mx_get_element_type(mode_t mode);
char* mx_get_element_name_link_to(char* path);
char* mx_get_element_xattrs(char* path);
bool mx_get_element_acl(char* path);
t_size* mx_get_element_size_major(char* tempPath);
t_size* mx_get_element_size_minor(char* tempPath);

//  ==Print==
void mx_print_usage(char err);
void mx_print_dir_err(char* dir);
void mx_print_l(t_shell* shell, int time_flag);
void mx_print_C(t_shell* shell);
void mx_print_one_col(t_shell* shell);
void mx_print_nspace(int count);
void mx_print_m(t_shell* shell);
void mx_print_element_name(t_element* el, bool isColored);


//  ==Sort==
int mx_sort_default(t_ls** ls_array);
int mx_sort_by_Size(t_ls** ls_array);
void mx_sort_by_time_c(t_shell* shell);
void mx_sort_by_time_t(t_shell* shell);
void mx_sort_by_time_u(t_shell* shell);
void mx_sort_reverse(t_shell* shell);

// ==Free==
void mx_free_shell(t_shell **shell);
void mx_free_ls(t_ls **ls);
void mx_free_element(t_element **element);
void mx_free_size(t_size **size);
void mx_free_date(t_date **date);

//  ==Other==
int mx_input_validation(int argc, char* argv[]);
int mx_open_dir(t_shell* shell);
int mx_shell_execute(t_shell* shell);
void mx_join_p(t_shell* shell);
void mx_execute_R(t_flags* flags, char** dirs);
