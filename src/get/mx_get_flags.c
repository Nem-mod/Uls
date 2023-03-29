#include "uls.h"

void mx_add_flag(t_flags* flags, char flag){
	if (flag == 'A') {
		if (!flags->a)
			flags->A = true;
		return;
	}
	if (flag == 'C') {
		flags->m = false;
		flags->l = false;
		flags->one = false;
		flags->C = true;
		return;
	}
	if (flag == 'G') {
		flags->G = true;
		return;
	}
	if (flag == 'S') {
		if (!flags->f) {
			flags->t = false;
			flags->S = true;
		}
		return;
	}
	if (flag == 'l') {
		flags->m = false;
		flags->l = true;
		flags->one = false;
		flags->C = false;
		return;
	}
	if (flag == 'a') {
		flags->A = false;
		flags->a = true;
		return;
	}
	if (flag == 't') {
		if (!flags->f && !flags->S)
			flags->t = true;
		return;
	}
	if (flag == 'u') {
		flags->c = false;
		flags->u = true;
		return;
	}
	if (flag == 'c') {
		flags->c = true;
		flags->u = false;
		return;
	}
	if (flag == 'f') {
		flags->S = false;
		flags->t = false;
		flags->f = true;
		mx_add_flag(flags, 'a');
		return;
	}
	if (flag == 'm') {
		flags->m = true;
		flags->l = false;
		flags->one = false;
		flags->C = false;
		return;
	}
	if (flag == 'p') {
		flags->p = true;
		return;
	}
	if (flag == '1') {
		flags->m = false;
		flags->l = false;
		flags->one = true;
		flags->C = false;
		return;
	}
	if (flag == 'T') {
		flags->T = true;
		return;
	}
	if (flag == 'R') {
		flags->R = true;
	}
	if (flag == 'r') {
		flags->r = true;
		return;
	}
}

t_flags* mx_get_flags(int argc, char* argv[]){
	t_flags* flags = mx_init_empty_flags();

	for(int i = 1; i < argc; i++) {
		if(argv[i][0] != '-')
			continue;

		for(int k = 1; k < mx_strlen(argv[i]); k++)
			mx_add_flag(flags, argv[i][k]);
  	}

    return flags;
}

void mx_sort_flags(char* flags);

void mx_del_flags_copy(char* flags);
