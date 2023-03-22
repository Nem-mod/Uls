#include "uls.h"

char* mx_input_validation(int argc, char* argv[]) {
	char* valid_flags = VALID_FLAGS;

	if(argc == 1) 
		return NULL;

	for(int i = 1; i < argc; i++) {	// Add dir validation!!!
		if(argv[i][0] != '-')
				continue;

		for(int k = 1; k < mx_strlen(argv[i]); k++) {
			if(!mx_strchr(valid_flags, argv[i][k]))
				return &argv[i][k];
		}
	}

	return NULL;
}


