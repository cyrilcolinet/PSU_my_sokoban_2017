/*
** EPITECH PROJECT, 2017
** my_strcmp
** File description:
** Behavior of strcmp function
*/

# include "my.h"

int my_strcmp(char *s1, char *s2)
{
	while (*s1 && *s2) {
		if (*s1 != *s2) {
			if (*s1 > *s2)
				return (-1);
			return (1);
		}
		s1++;
		s2++;
	}
	return (*s2 - *s1);
}
