/*
** EPITECH PROJECT, 2017
** my_strlowercase
** File description:
** Transform all characters of a string into capital letters
*/

# include "my.h"

char *my_strlowcase(char *str)
{
	int i = 0;
	while (str[i] != '\0') {
		if (str[i] >= 'A' && str[i] <= 'Z')
			str[i] = 'a' + str[i] - 'A';
		i++;
	}
	return (str);
}
