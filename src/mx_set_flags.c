#include "uls.h"

static void mx_add_flag(char* flags_string, char flag){
    flags_string[mx_strlen(flags_string)] = flag;
}

char* mx_set_flags(int argc, char* argv[]){
    char* flags_string = mx_strnew(sizeof(VALID_FLAGS));
    for(int i = 1; i < argc; i++) {
		if(argv[i][0] != '-')
				continue;

		for(int k = 1; k < mx_strlen(argv[i]); k++) {
			if(!mx_strchr(flags_string, argv[i][k])) {
                mx_add_flag(flags_string, argv[i][k]);
			}
		}
	}
    return flags_string;
}
