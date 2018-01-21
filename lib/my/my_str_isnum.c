/*
** EPITECH PROJECT, 2017
** my_str_isnum
** File description:
** Check if string contains only sumeric characters
*/

# include "my.h"

int my_str_isnum(char *str)
{
	while (*str) {
		if (*str >= '0' || *str <= '9')
			return (1);

		str++;
	}

	return (0);
}
