/*
** EPITECH PROJECT, 2017
** my_str_isnum
** File description:
** Check if string contains only sumeric characters
*/

# include <stdbool.h>
# include "my.h"

int my_str_isnum(char *str, bool neg)
{
	if (str[0] == '-' && neg)
		str++;

	while (*str) {
		if (*str < '0' || *str > '9')
			return (false);

		str++;
	}

	return (true);
}
