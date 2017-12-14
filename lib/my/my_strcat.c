/*
** EPITECH PROJECT, 2017
** my_strcat
** File description:
** Concatenate two strings
*/

# include "my.h"

char *my_strcat(char *dest, char *src)
{
	int i = 0;
	int strlen = my_strlen(src);
	while (src[i] != '\0') {
		dest[i + strlen] = src[i];
		i++;
	}
	dest[i + strlen] = '\0';
	return (dest);
}
