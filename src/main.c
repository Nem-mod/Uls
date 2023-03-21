#include "uls.h"


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <pwd.h>
#include <grp.h>
#include <time.h>

void print_permissions(mode_t mode) {
    printf((S_ISDIR(mode)) ? "d" : "-");
    printf((mode & S_IRUSR) ? "r" : "-");
    printf((mode & S_IWUSR) ? "w" : "-");
    printf((mode & S_IXUSR) ? "x" : "-");
    printf((mode & S_IRGRP) ? "r" : "-");
    printf((mode & S_IWGRP) ? "w" : "-");
    printf((mode & S_IXGRP) ? "x" : "-");
    printf((mode & S_IROTH) ? "r" : "-");
    printf((mode & S_IWOTH) ? "w" : "-");
    printf((mode & S_IXOTH) ? "x" : "-");
}

void ls_l(char* path) {
    DIR* dir;
    struct dirent* ent;
    struct stat file_stat;
    struct passwd* user_info;
    struct group* group_info;
    char date[20];

    if ((dir = opendir(path)) == NULL) {
        perror("opendir failed");
        exit(EXIT_FAILURE);
    }

    while ((ent = readdir(dir)) != NULL) {
        char file_path[1024];
        sprintf(file_path, "%s/%s", path, ent->d_name);

        if (stat(file_path, &file_stat) < 0) {
            perror("stat failed");
            exit(EXIT_FAILURE);
        }

        print_permissions(file_stat.st_mode);
        printf(" %2lu ", file_stat.st_nlink);

        if ((user_info = getpwuid(file_stat.st_uid)) != NULL) {
            printf("%-8s ", user_info->pw_name);
        } else {
            printf("%-8d ", file_stat.st_uid);
        }

        if ((group_info = getgrgid(file_stat.st_gid)) != NULL) {
            printf("%-8s ", group_info->gr_name);
        } else {
            printf("%-8d ", file_stat.st_gid);
        }

        printf("%6ld ", file_stat.st_size);

        strftime(date, 20, "%b %d %H:%M", localtime(&file_stat.st_mtime));
        printf("%s ", date);

        printf("%s\n", ent->d_name);
    }

    closedir(dir);
}

int main(int argc, char* argv[]) {

	mx_input_validation(argc, argv);
	t_shell* shell = mx_create_shell(argc, argv);
	// mx_printstr(shell->flags);
	// mx_printstr("\n");
	// mx_print_strarr(shell->dirs, " ");

	DIR *dir;
    struct dirent *entry;

	int i = 0;
	while (shell->dirs[i]){

		if ((dir = opendir(shell->dirs[i])) == NULL) {
			perror("opendir error");
			exit(EXIT_FAILURE);
		}

		while ((entry = readdir(dir)) != NULL) {
			if(!mx_strcmp(entry->d_name, ".") || !mx_strcmp(entry->d_name, "..") )
				continue;
				
			printf("%s ", entry->d_name);
		}

		i++;
	}
	
	ls_l(shell->dirs[0]);
    closedir(dir);
	return 0;
}

