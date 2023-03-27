#include "uls.h"

void mx_add_flag(char* flags_string, char flag){
    flags_string[mx_strlen(flags_string)] = flag;
}

char* mx_get_flags(int argc, char* argv[]){
  int len = 0;

  for (int i = 1; i < argc; i++)
    if (argv[i][0] == '-')
    	len += mx_strlen(argv[i]);

	char* flags_string = mx_strnew(sizeof(char) * len);

	for(int i = 1; i < argc; i++) {
		if(argv[i][0] != '-')
			continue;

		for(int k = 1; k < mx_strlen(argv[i]); k++)
			mx_add_flag(flags_string, argv[i][k]);
  	}

    return flags_string;
}

void mx_sort_flags(char* flags);

void mx_del_flags_copy(char* flags);
