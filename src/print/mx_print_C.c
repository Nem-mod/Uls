#include "uls.h"

static void print_tab(int max_len, char *name) {
    int ntab = 0;
    int diff = max_len - mx_strlen(name);
    ntab = diff / TWO_TABS;
    if (diff % TWO_TABS != 0)
        ntab++;

    for (int tab_index = 0; tab_index < ntab; tab_index++)
        mx_printchar('\t');
}


void mx_print_C(t_shell* shell){
    t_ls** ls_array = shell->ls_array;
    struct winsize win;
    ioctl(0, TIOCGWINSZ, &win);

    for (int i = 0;  i < shell->ls_count; i++) {
        if (shell->ls_count != 1) {
            mx_printstr(ls_array[i]->name);
            mx_printstr(":\n");   
        }

        int col_w = (TWO_TABS) - (shell->ls_array[i]->max_len_name % (TWO_TABS)) + shell->ls_array[i]->max_len_name;
        int n_col = win.ws_col / col_w;
        int n_row = shell->ls_array[i]->elements_count / n_col;

        if (n_row == 0 || shell->ls_array[i]->elements_count  % n_col != 0) 
            n_row++;

        for (int row = 0; row < n_row; row++) {
            for (int column = 0; column < n_col; column++) {
                int index = row + (column * n_row);

                if (index >= shell->ls_array[i]->elements_count)
                    break;   

                if(shell->ls_array[i]->elements[index]->name) 
                    mx_print_element_name(ls_array[i]->elements[index], shell->flags->G);

                if (column < n_col - 1 && row + ((column + 1) * n_row) < shell->ls_array[i]->elements_count)
                // if (column != n_col - 1)
                    print_tab(col_w, ls_array[i]->elements[index]->name); 
            }
            mx_printchar('\n');
        }

        if (i != shell->ls_count - 1)
            mx_printchar('\n');
    }
}
