#include "uls.h"

// TODO: close dirs
char** mx_get_dirs(int argc, char* argv[]){
	char** array_of_ex_dirictories = mx_create_char_arr(argc);
	int k = 0;
	int e = 0;
	DIR* dir;

	for(int i = 1; i < argc; i++) {
		if(argv[i][0] == '-')
			continue;
		
		dir = opendir(argv[i]);
		
		if(dir == NULL) {
			mx_print_dir_err(argv[i]);
			e++;
			closedir(dir);
			continue;
		}
		
		array_of_ex_dirictories[k] = mx_strdup(argv[i]);
		k++;
		closedir(dir);
	}
	array_of_ex_dirictories[k] = NULL;
	if (k == 0)
		array_of_ex_dirictories[0] = mx_strdup(".");
	
	mx_bubble_sort(array_of_ex_dirictories, k);
	
	return array_of_ex_dirictories;
}

