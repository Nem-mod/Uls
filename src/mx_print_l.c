#include "uls.h"

void mx_print_l(t_ls** ls_array) {
    int k = 0;
    while (ls_array[k]) {
        for (int i = 0; i < ls_array[k]->elements_count; i++) {
            mx_printstr(ls_array[k]->elements[i].permission);
            mx_printchar('\t');
            mx_printint(ls_array[k]->elements[i].links);
            mx_printchar('\t');
            mx_printstr(ls_array[k]->elements[i].owner_name);
            mx_printchar('\t');
            mx_printstr(ls_array[k]->elements[i].group_name);
            mx_printchar('\t');
            mx_printint(ls_array[k]->elements[i].size->size);
            mx_printchar('\t');
            mx_printstr(ls_array[k]->elements[i].name);
            mx_printchar('\n');
        }
        k++;
    }
    
   
}
