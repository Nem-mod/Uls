#include "uls.h"

static int get_last_entry_of_display_mode(t_flags* flags) {
    // int mode = DISPLAY_MODE_NONE;
    // for (int i = 0; i < mx_strlen(flags); i++) {
    //     if(flags[i] == 'l')
    //         mode = DISPLAY_MODE_l;
    //     if(flags[i] == '1')
    //         mode = DISPLAY_MODE_1;
    //     if(flags[i] == 'C')
    //         mode = DISPLAY_MODE_C;
    //     if(flags[i] == 'm')
    //         mode = DISPLAY_MODE_m;
    // }
    // return mode;    
    if (flags->l)
        return DISPLAY_MODE_l;
    if (flags->one)
        return DISPLAY_MODE_1;
    if (flags->C)
        return DISPLAY_MODE_C;
    if (flags->m)
        return DISPLAY_MODE_m;
    return DISPLAY_MODE_NONE;
}

static int get_last_entry_of_display_time(t_flags* flags) {
    // int mode = DISPLAY_TIME_MODE_DEFAULT;
    // for (int i = 0; i < mx_strlen(flags); i++) {
    //     if(flags[i] == 'u')
    //         mode = DISPLAY_TIME_MODE_u;
    //     if(flags[i] == 'c')
    //         mode = DISPLAY_TIME_MODE_c;
    // }
    // return mode;
    if (flags->u)
        return DISPLAY_TIME_MODE_u;
    if (flags->c)
        return DISPLAY_TIME_MODE_c;
    return DISPLAY_TIME_MODE_DEFAULT;
}

static int get_sort_mode(t_flags* flags) {
    // int mode = SORT_DEFAULT;
    // for (int i = 0; i < mx_strlen(flags); i++) {
    //     if(flags[i] == 'f')
    //         mode = WITHOUT_SORT;
    //     if(flags[i] == 'S' && mode != WITHOUT_SORT)
    //         mode = SORT_BY_SIZE;
    //     if(flags[i] == 't' && mode != WITHOUT_SORT && mode != SORT_BY_SIZE)
    //         mode = SORT_BY_TIME;
    // }
    // return mode;
    // mx_printint(flags->f);
    // mx_printint(flags->S);
    // mx_printint(flags->t);
    // mx_printchar('\n');
    if (flags->f)
        return WITHOUT_SORT;
    if (flags->S)
        return SORT_BY_SIZE;
    if (flags->t)
        return SORT_BY_TIME;
    return SORT_DEFAULT;
}

static int get_visibility_mode(t_flags* flags) {
    // int mode = VISIBILITY_MODE_vis;
    // for (int i = 0; i < mx_strlen(flags); i++) {
    //     if(flags[i] == 'a')
    //         mode = VISIBILITY_MODE_a;
    //     if(flags[i] == 'A' && mode != VISIBILITY_MODE_a)
    //         mode = VISIBILITY_MODE_A;
    // }
    // return mode;
    if (flags->a)
        return VISIBILITY_MODE_a;
    if (flags->A)
        return VISIBILITY_MODE_A;
    return VISIBILITY_MODE_vis;
}

t_shell* mx_create_shell(t_flags* flags, char** dirs) {
    t_shell* shell = malloc(sizeof(t_shell));
    int amount_of_dirs;
    
    shell->flags = flags;
    shell->dirs = dirs;
    amount_of_dirs = mx_get_size_array_of_strings(shell->dirs);
    
    shell->display_mode = get_last_entry_of_display_mode(shell->flags);
    shell->display_time_mode = get_last_entry_of_display_time(shell->flags);
    shell->sort_mode = get_sort_mode(shell->flags);
    shell->visibility_mode = get_visibility_mode(shell->flags);
    shell->ls_count = amount_of_dirs;
    shell->ls_array = mx_create_ls_array(shell->ls_count, shell->dirs, shell->visibility_mode);
    return shell;
}
