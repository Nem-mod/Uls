#include "uls.h"

char** mx_get_dirs(int argc, char* argv[]){
	char** array_of_ex_dirictories = mx_create_char_arr(argc);
	int k = 0;

	for(int i = 1; i < argc; i++) {
		if(argv[i][0] == '-')
			continue;
		array_of_ex_dirictories[k] = mx_strdup(argv[i]);
		k++;
	}
	
	return array_of_ex_dirictories;
}

