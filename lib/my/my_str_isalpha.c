/*
** EPITECH PROJECT, 2017
** my_isalpha
** File description:
** Return 1 if the string given as parameter is composed to only alphanumeric charcaters, and 0 if not
*/

# include "my.h"

int my_str_isalpha(char *str)
{
	int i = 0;
	while (str[i] != '\0') {
		if ((str[i] < 'a' || str[i] > 'z') &&
		    (str[i] < 'A' || str[i] > 'Z'))
			return (0);
		i++;
	}
	return (1);
}
