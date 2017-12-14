/*
** EPITECH PROJECT, 2017
** my_strncmp
** File description:
** Behavior of strncmp function
*/

# include "my.h"

int my_strncmp(char *s1, char *s2, int n)
{
	int i = 0;
	int result = 0;
	while (s1[i] != '\0' && s2[i] != '\0' && i < n) {
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	if (i < n)
		result = s1[i] - s2[i];
	else
		result = 0;
	return (result);
}
