#include "uls.h"

void mx_print_C(t_shell* shell){
    t_ls** ls_array = shell->ls_array;

    for (int i = 0;  i < shell->ls_count; i++) {
        if (shell->ls_count != 1) {
            mx_printstr(ls_array[i]->name);
            mx_printstr(":\n");   
        }
        char* flag_a = mx_strchr(shell->flags, 'a');
        char* flag_A = mx_strchr(shell->flags, 'A');
        for (int k = 0; k < ls_array[i]->elements_count; k++) {
            
            
            if (!ls_array[i]->elements[k].isVisible 
            && !flag_a
            && !flag_A)
                continue;
            if(flag_A 
            && (!mx_strcmp(ls_array[i]->elements[k].name, ".")
            || !mx_strcmp(ls_array[i]->elements[k].name, ".."))) {
                continue;
            }
            
            mx_printstr(ls_array[i]->elements[k].name);
            mx_printchar(' ');
        }
        if (i != shell->ls_count - 1)
            mx_printchar('\n');
        mx_printchar('\n');
    }
}
