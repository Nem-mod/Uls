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
#define VALID_FLAGS "l"

typedef struct s_element {

    char* name;

}               t_element;

typedef struct s_ls {
    
    char* path;
    // char* flags;
    int elements_count;
    t_element* elements;

}               t_ls;

typedef struct s_shell {

    char* flags;
    char** dirs;

}              t_shell;

char* mx_input_validation(int argc, char* argv[]);
void mx_print_usage(char err);
void mx_add_flag(char* flags_string, char flag);
char* mx_get_flags(int argc, char* argv[]);
char** mx_get_dirs(int argc, char* argv[]);
t_shell* mx_create_shell(int argc, char* argv[]);
t_ls* mx_create_ls(char* path);
void mx_set_element_info(t_element* element, struct dirent* entry);
char* mx_get_element_name(struct dirent* entry);

// void mx_ls(t_shell* shell);

int mx_open_dir(t_shell* shell);

