/*
** EPITECH PROJECT, 2018
** my_library
** File description:
** my_strjoin function
*/

# include <stdlib.h>
# include "my.h"

char *my_strjoin(char *str1, char *str2)
{
	char *new;
	size_t i = 0, j = 0, str1len = 0, str2len = 0;

	if (str1 == NULL)
		return (NULL);
	if (str2 == NULL)
		return (my_strdup(str1));

	str1len = my_strlen(str1);
	str2len = my_strlen(str2);
	new = my_strconfigure(str1len + str2len + 1);

	if (new == NULL)
		return (NULL);

	while (i++ < str1len)
		*(new + i) = *(str1 + i);
	while (j++ < str2len)
		*(new + i++) = *(str2 + j);
	return (new);
}