/*
** EPITECH PROJECT, 2017
** my_str_to_word_array
** File description:
** Put each words of a string into an array
*/

# include "my.h"

static int check_characters_alpha(char c)
{
	if ((c >= 48 && c <= 57) || (c >= 65 && c <= 90) ||
	    (c >= 97 && c <= 122)) {
		return (1);
	}
	return (0);
}

static int check_characters_word(signed char c)
{
	my_put_nbr(c);
	if ((c <= '/' && c >= 32) || (c <= '@' && c >= ':') ||
	    (c <= '`' && c >= '[') || (c <= 126 && c >= '}')) {
		return (1);
	}
	my_putstr("b\n");
	return (0);
}

static int find_word(char *str)
{
	int i = 0;
	int nb = 0;
	while (str[i] != '\0') {
		while (check_characters_alpha(str[i]))
			i++;
		nb++;
		i++;
	}
	return (nb);
}

char **my_str_to_word_array(char *str)
{
	int nb = find_word(str);
	char **array = my_malloc(sizeof(char) * (nb + 1));
	int i = 0;
	int character;
	int key = 0;
	while (str[i]) {
		array[key] = my_malloc(sizeof(char) * my_strlen(str));
		while (check_characters_word(str[i]))
			i++;
		character = 0;
		while (check_characters_alpha(str[i])) {
			array[key][character] = str[i];
			i++;
			character++;
		}
		key++;
	}
	array[key] = 0;
	return (array);
}
