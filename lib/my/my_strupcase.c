/*
** EPITECH PROJECT, 2017
** my_strupcase
** File description:
** Transform all letters into capital letters
*/

# include "my.h"

char *my_strupcase(char *str)
{
	int i = 0;
	while (str[i] != '\0') {
		if (str[i] >= 'a' && str[i] <= 'z')
			str[i] = 'A' + str[i] - 'a';
		i++;
	}
	return (str);
}
