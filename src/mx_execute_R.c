#include "uls.h"


void mx_execute_R(t_flags* flags, char** dirs) {
    int d = 0;
    while (dirs[d]) {
        char** arr = malloc(sizeof(char*));
        *arr = mx_strdup(dirs[d]);
        arr[1] = NULL;
        t_shell* shell = mx_create_shell(flags, arr);
        if(dirs[1] != NULL) {
            mx_printstr(dirs[d]);
            mx_printstr(":\n");
        }
	    mx_shell_execute(shell);
        

        for (int i = 0; i < shell->ls_array[0]->elements_count; i++) {
            if (shell->ls_array[0]->elements[i].is_dir) {
                mx_printstr("\n");
                char* temp = mx_strdup(shell->ls_array[0]->elements[i].path);
                char** tarr = malloc(sizeof(char*));
                tarr[0] = temp;
                tarr[1] = NULL;
                mx_printstr(temp);
                mx_printstr(":\n");
                mx_execute_R(shell->flags, tarr);
                mx_del_strarr(&tarr);
            } 
            else continue;
            
        }
        mx_del_strarr(&arr);
        d++;
    }
}
