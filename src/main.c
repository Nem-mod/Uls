#include "uls.h"

// TODO: normal error handle
int main(int argc, char* argv[]) {
    int err_flag = mx_input_validation(argc, argv);

	if (err_flag != 0) {
        return -1;
    }
    
    // TODO: free -R flag and this too
    t_flags* flags = mx_get_flags(argc, argv);  // need free
    char** dirs = mx_get_dirs(argc, argv);  // need free

    if (flags->R) {
        mx_execute_R(flags, dirs); 
        free(flags);
        flags = NULL; 
        return 0;
    }
    
	t_shell* shell = mx_create_shell(flags, dirs);
	mx_shell_execute(shell);

    mx_free_shell(&shell);
    
    return 0;
}
