/*
** EPITECH PROJECT, 2017
** my_strncpy
** File description:
** Copie the n characters of a string given as parameter into another
*/

# include "my.h"

char *my_strncpy(char *dest, char *src, int n)
{
	int i = 0;
	while (i < n && src[i] != '\0') {
		dest[i] = src[i];
		i++;
	}
	while (i < n) {
		dest[i] = 0;
		i++;
	}
	return (dest);
}
