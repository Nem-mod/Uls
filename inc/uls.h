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

#define VALID_FLAGS "ACGRSTaclmrtu1"

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

