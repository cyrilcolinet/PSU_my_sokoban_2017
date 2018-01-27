/*
** EPITECH PROJECT, 2018
** my_library
** File description:
** my_strchr function
*/

# include "my.h"

char *my_strchr(char *str, char delim)
{
	int i = 0;

	while (i < my_strlen(str) + 1) {
		if (*(str + i) == delim)
			return (str + i);
		i++;
	}

	return (NULL);
}