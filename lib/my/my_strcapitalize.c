/*
** EPITECH PROJECT, 2017
** my_strcapitalize
** File description:
** Remplace the first letter of each words into a capital letter
*/

# include "my.h"

char *my_strcapitalize(char *str)
{
	int strlen = my_strlen(str);
	for (int i = 0; i < strlen; i++) {
		if (my_str_isalpha(str) && (str[(i - 1)] == ' ' || i == 0))
			str[i] -= 32;
	}
	return (str);
}
