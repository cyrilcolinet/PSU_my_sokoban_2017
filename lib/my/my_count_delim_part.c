/*
** EPITECH PROJECT, 2018
** library
** File description:
** count_delimiter_parts function
*/

# include <stdbool.h>
# include "my.h"

static bool cts(char c, char *str)
{
	int i;

	if (!c)
		return (true);

	for (i = 0; str[i]; i++) {
		if (str[i] == c)
			return (true);
	}

	return (false);
}

int my_count_delim_part(char *str, char *delim)
{
	int count = 0;
	int i;

	for (i = 0; str[i]; i++) {
		if (!cts(str[i], delim) && cts(str[i + 1], delim))
			count++;
	}

	return (count);
}