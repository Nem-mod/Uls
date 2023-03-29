#include "uls.h"

char** mx_get_dirs(int argc, char* argv[]){
	char** array_of_ex_dirictories = mx_create_char_arr(argc);
	int k = 0;

	for(int i = 1; i < argc; i++) {
		if(argv[i][0] == '-')
			continue;
		
		if(opendir(argv[i]) == NULL) {
			mx_print_dir_err(argv[i]);
			continue;
		}
		
		array_of_ex_dirictories[k] = mx_strdup(argv[i]);
		k++;
	}
	array_of_ex_dirictories[k] = NULL;
	if (k == 0) {
		array_of_ex_dirictories[0] = mx_strdup(".");
	}
	
	mx_bubble_sort(array_of_ex_dirictories, k); // Refactor for -f flag!!!
	
	return array_of_ex_dirictories;
}

