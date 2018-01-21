/*
** EPITECH PROJECT, 2018
** libmy_printf
** File description:
** utils functions
*/

# include "my_printf.h"

pf set_function(int offset)
{
	pf ret = NULL;

	if (offset == 0) ret = flag_d;
	else if (offset == 1) ret = flag_d;
	else if (offset == 2) ret = flag_s;
	else if (offset == 3) ret = flag_S;
	else if (offset == 4) ret = flag_c;
	//else if (offset == 5) ret = flag_p;
	else if (offset == 6) ret = flag_x;
	else if (offset == 7) ret = flag_X;
	else if (offset == 8) ret = flag_o;
	else if (offset == 9) ret = flag_b;
	else if (offset == 10) ret = flag_m;
	else if (offset == 11) ret = flag_u;
	else if (offset == 12) ret = flag_n;
	else if (offset == 13) ret = flag_percent;
	else if (offset == 14) ret = flag_d;
	else if (offset == 15) ret = flag_d;

	return (ret);
}

pf *flag_functions(pf **arr)
{
	int i;
	*arr = (pf*)malloc(sizeof(pf) * 17);

	if (*arr == NULL) {
		write(2, "Malloc failed. Aborded.\n", 24);
		return (NULL);
	}

	for (i = 0; i < 17; i++)
		(*arr)[i] = set_function(i);

	return (*arr);
}

void configure(param_t *param, char *flags)
{
	pf *func = flag_functions(&func);

	while (*flags) {
		param->flag = *flags;
		param->fct = *func;
		flags++;
		func++;
		param++;
	}
}