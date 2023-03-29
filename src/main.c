#include "uls.h"

int main(int argc, char* argv[]) {
    int err_flag = mx_input_validation(argc, argv);

	if (err_flag != 0) {
        return -1;
    }

    t_flags* flags = mx_get_flags(argc, argv);
    char** dirs = mx_get_dirs(argc, argv);
    
    if (flags->R) {
        mx_execute_R(flags, dirs); 
        return 0;
    }
    
	t_shell* shell = mx_create_shell(flags, dirs);
	mx_shell_execute(shell);
    
    return 0;
}
