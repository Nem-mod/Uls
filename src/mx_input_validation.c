#include "uls.h"

int mx_input_validation(int argc, char* argv[]) {
	char* valid_flags = VALID_FLAGS;

	if(argc == 1) 
		return 0;

	for(int i = 1; i < argc; i++) {
		if(argv[i][0] != '-'){
			continue;
		}
				

		for(int k = 1; k < mx_strlen(argv[i]); k++) {
			if(!mx_strchr(valid_flags, argv[i][k])) {
				mx_print_usage(argv[i][k]);
				return 1;
			}
		}
	}

	return 0;
}


