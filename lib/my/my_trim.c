/*
** EPITECH PROJECT, 2017
** my_trim
** File description:
** Trim spaces
*/

# include "my.h"

char *my_trim(char *str)
{
	int offset2 = 0;
	int offset1 = 0;
	char *res = my_malloc(sizeof(char *) * (my_strlen(str) + 1));
	while (str[offset1]) {
		if (str[offset1] != ' ')
			res[(offset2++)] = str[offset1];
		offset1++;
	}
	res[offset2] = 0;
	return (res);
}
