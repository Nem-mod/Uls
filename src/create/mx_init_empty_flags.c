#include "uls.h"

t_flags* mx_init_empty_flags() {
    t_flags* flags = malloc(sizeof(t_flags));

    flags->A = false;
    flags->C = false;
    flags->G = false;
    flags->S = false;
    flags->l = false;
    flags->a = false;
    flags->t = false;
    flags->u = false;
    flags->c = false;
    flags->f = false;
    flags->m = false;
    flags->p = false;
    flags->one = false;
    flags->T = false;
    flags->t = false;
    flags->r = false;
    flags->R = false;
    flags->dog = false;

    return flags;
}
