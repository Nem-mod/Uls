#include "uls.h"

void mx_print_C(t_shell* shell){
    t_ls** ls_array = shell->ls_array;
    struct winsize win;
    ioctl(STDOUT_FILENO, TIOCGWINSZ, &win);
    //mx_printint(win.ws_col);

    //int cl = 0;
    for (int i = 0;  i < shell->ls_count; i++) {
        if (shell->ls_count != 1) {
            mx_printstr(ls_array[i]->name);
            mx_printstr(":\n");   
        }
        //int cols = win.ws_col / shell->ls_array[i]->max_len_name;
        
        // mx_printint(cols);
        // mx_printchar('\n');
        
        //mx_printint(shell->ls_array[i]->elements_count);
        for (int k = 0; k < ls_array[i]->elements_count; k++) {
            
            mx_printstr(ls_array[i]->elements[k].name);
            mx_printchar(' ');
        }
        if (i != shell->ls_count - 1)
            mx_printchar('\n');
        mx_printchar('\n');
    }
}
