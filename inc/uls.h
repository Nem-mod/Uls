#pragma once

#include <stdio.h>
#include "libmx.h"

#define VALID_FLAGS "ACGRSTaclmrtu1"
#include <stdio.h>
#include <dirent.h>
#include <errno.h>
#include <stdlib.h>

void mx_input_validation(int argc, char* argv[]);
void mx_print_usage(char err);


typedef struct s_shell {

    char* flags;
    char** dirs;

}              t_shell;


char* mx_set_flags(int argc, char* argv[]);
char** mx_set_dirs(int argc, char* argv[]);
t_shell* mx_create_shell(int argc, char* argv[]);

void mx_ls(t_shell* shell);

int mx_open_dir(t_shell* shell);

