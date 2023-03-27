#include "uls.h"

int main(int argc, char* argv[]) {
    int err_flag = mx_input_validation(argc, argv);

	if (err_flag != 0) {
        return -1;
    }
	t_shell* shell = mx_create_shell(argc, argv);
	
	mx_shell_execute(shell);
    
    return 0;
	
}
