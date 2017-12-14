/*
** EPITECH PROJECT, 2017
** my_revstr
** File description:
** Reverse all characters of a string
*/

# include "my.h"

static void my_revstr_swap(char *p1, char *p2)
{
	char tmp = *p1;
	*p2 = *p1;
	*p1 = tmp;
}

char *my_revstr(char *str)
{
	int len = my_strlen(str);
	int i = 0;

	while (i < len / 2) {
		my_revstr_swap(&str[i], &str[len - 1 - i]);
		i++;
	}

	str[len] = '\0';
	return (str);
}
