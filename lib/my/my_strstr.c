/*
** EPITECH PROJECT, 2017
** my_strstr
** File description:
** Behavior of the strstr function
*/

# include "my.h"

char *my_strstr(char *str, char *to_find)
{
	int i;
	int j = 0;

	if (to_find[0] == '\0')
		return (str);

	while (str[j] != '\0') {
		i = 0;
		while (to_find[i] == str[i + j]) {
			if (to_find[i] != '\0' && to_find[i + 1] == '\0')
				return (&str[j]);
			else if (str[j] == '\0')
				return (0);
			i++;
		}
		j++;
	}

	return (0);
}
