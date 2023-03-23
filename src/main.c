#include "uls.h"

int main(int argc, char* argv[]) {
    int err_flag = mx_input_validation(argc, argv);

	if (err_flag != 0) {
        return -1;
    }

	t_shell* shell = mx_create_shell(argc, argv);
	
	// mx_print_strarr(shell->dirs, "\n");
	mx_shell_execute(shell);
    // t_ls* ls = mx_create_ls("./");

    // for (int i = 0; i < ls->elements_count; i++) {
		// mx_printstr(ls->elements[i].permission);
		// mx_printchar('\t');
		// mx_printint(ls->elements[i].links);
		// mx_printchar('\t');
		// mx_printstr(ls->elements[i].owner_name);
		// mx_printchar('\t');
		// mx_printstr(ls->elements[i].group_name);
		// mx_printchar('\t');
		// mx_printint(ls->elements[i].size->size);
		// mx_printchar('\t');
		// mx_printstr(ls->elements[i].access_date->long_date);
        // mx_printstr(ls->elements[i].name);
        // mx_printchar('\n');
    // }

	// struct timespec ts;    
	// //clock_gettime(CLOCK_REALTIME, &ts);

	// char * p = ctime(&ts.tv_sec); /* Note that ctime() isn't thread-safe. */
	// // p[strcspn(p, "\r\n")] = 0;

	// printf("Date: %s %ldns\n", p, ts.tv_nsec);

    return 0;
	// DIR *dir;
    // struct dirent *entry;

	// int i = 0;
	// while (shell->dirs[i]){

	// 	if ((dir = opendir(shell->dirs[i])) == NULL) {
	// 		perror("opendir error");
	// 		exit(EXIT_FAILURE);
	// 	}

	// 	while ((entry = readdir(dir)) != NULL) {
	// 		if(!mx_strcmp(entry->d_name, ".") || !mx_strcmp(entry->d_name, "..") )
	// 			continue;
				
	// 		printf("%s ", entry->d_name);
	// 	}

	// 	i++;
	// }
	
	// ls_l(shell->dirs[0]);
    // closedir(dir);
	// return 0;
}

