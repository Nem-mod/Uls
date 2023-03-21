#include "uls.h"

int main(int argc, char* argv[]) {

	mx_input_validation(argc, argv);
	t_shell* shell = mx_create_shell(argc, argv);
	mx_printstr(shell->flags);
	mx_printstr("\n");
	mx_print_strarr(shell->dirs, " ");
	return 0;
}

