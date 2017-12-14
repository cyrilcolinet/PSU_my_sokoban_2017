/*
** EPITECH PROJECT, 2017
** my_show_word_array
** File description:
** Function that displays the content of an array of words. There must be one word per line, and each word must end with carriage return, including the last one
*/

# include "my.h"

void my_show_word_array(char * const *tab)
{
	int i = 0;
	while (tab[i] != 0) {
		if (my_str_isalpha(tab[i]) && tab[i][0] != '\0') {
			my_putstr(tab[i]);
			my_putchar('\n');
			i++;
		}
	}
}
