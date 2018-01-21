/*
** EPITECH PROJECT, 2018
** my_realloc
** File description:
** my_realloc function
*/

# include <stdlib.h>
# include "my.h"

char *my_realloc(char *ptr, unsigned int size)
{
	char *new_ptr;
	unsigned int ch = 0;

	if (ptr == NULL || size < 1)
		return (NULL);

	new_ptr = malloc(sizeof(*new_ptr) * (size + 1));

	if (new_ptr == NULL)
		return (NULL);

	while (ch != size && ptr[ch] != 0) {
		new_ptr[ch] = ptr[ch];
		ch++;
	}

	if (ptr[ch])
		while (ch < size)
			new_ptr[ch++] = 0;

	new_ptr[ch] = 0;
	free(ptr);
	return (new_ptr);
}