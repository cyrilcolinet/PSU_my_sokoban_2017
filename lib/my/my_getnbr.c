/*
** EPITECH PROJECT, 2017
** my_getnbr
** File description:
** Get number of a string
*/

# include "my.h"

static char my_get_sign(char *str)
{
	int i = 0;
	int minus_count = 0;
	
	while (str[i] == '-' || str[i] == '+') {
		if (str[i] == '-')
			minus_count++;
		i++;
	}

	if ((minus_count % 2) != 0)
		return ('-');
	else
		return ('+');
}

static int my_comp_beg_off(char *str)
{
	int i = 0;

	while (str[i] == '+' || str[i] == '-') {
		i++;
	}

	return (i);
}

int my_getnbr(char *str)
{
	int n = 0;
	char *p1 = str + my_comp_beg_off(str);

	while ((*p1 >= '0' && *p1 <= '9') && *p1 != '\0') {
		n = (n + (*p1) - '0') * 10;
		p1++;
	}

	n /= 10;

	if (my_get_sign(str) == '-')
		n = -n;

	return (n);
}
