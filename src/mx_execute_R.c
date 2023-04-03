#include "uls.h"


void mx_execute_R(t_flags* flags, char** dirs) {
    // int d = 0;
    // while (dirs[d]) {
    //     char** arr = malloc(sizeof(char*)); // TODO: check for free

    //     *arr = mx_strdup(dirs[d]); // TODO: check for free
    //     arr[1] = NULL;

    //     t_shell* shell = mx_create_shell(flags, arr); // FIXME: free
        
    //     if(dirs[1] != NULL) {
    //         mx_printstr(dirs[d]);
    //         mx_printstr(":\n");
    //     }
	//     mx_shell_execute(shell);
        
    //     for (int i = 0; i < shell->ls_array[0]->elements_count; i++) {
    //         if (shell->ls_array[0]->elements[i]->is_dir) {
    //             char* temp = mx_strdup(shell->ls_array[0]->elements[i]->path); // FIXME: free
    //             char** tarr = malloc(sizeof(char*)); // TODO: check for free

    //             tarr[0] = temp;
    //             tarr[1] = NULL;

    //             mx_printstr("\n");
    //             mx_printstr(temp);
    //             mx_printstr(":\n");

    //             mx_execute_R(shell->flags, tarr);
    //             mx_del_strarr(&tarr);
    //         }  
    //     }
    //     mx_del_strarr(&arr);

    //     d++;
    //     if(dirs[d] != NULL)
    //         mx_printstr("\n");
    // }
        int d = 0;
    while (dirs[d]) {
        char** arr = malloc(sizeof(char*) * 2); // TODO: check for free

        *arr = mx_strdup(dirs[d]); // TODO: check for free
        arr[1] = NULL;

        t_shell* shell = mx_create_shell(flags, arr); // TODO: check for free
        
        if(dirs[1] != NULL) {
            mx_printstr(dirs[d]);
            mx_printstr(":\n");
        }
	    mx_shell_execute(shell);
        
        for (int i = 0; i < shell->ls_array[0]->elements_count; i++) {
            if (shell->ls_array[0]->elements[i]->is_dir) {
                if (mx_strcmp(shell->ls_array[0]->elements[i]->name, "..") == 0 ||
                    mx_strcmp(shell->ls_array[0]->elements[i]->name, ".") == 0)
                    continue;
                char* temp = mx_strdup(shell->ls_array[0]->elements[i]->path); // TODO: check for free
                char** tarr = malloc(sizeof(char*) * 2); // TODO: check for free

                tarr[0] = temp;
                tarr[1] = NULL;

                mx_printstr("\n");
                mx_printstr(temp);
                mx_printstr(":\n");

                mx_execute_R(shell->flags, tarr);
            }  
        }
        mx_del_strarr(&(shell)->dirs);

        for (int i = 0; i < (shell)->ls_count; i++)
            mx_free_ls(&(shell)->ls_array[i]);
        free((shell)->ls_array);
        free(shell);

        d++;
        if(dirs[d] != NULL)
            mx_printstr("\n");
    }
    mx_del_strarr(&dirs);
}
