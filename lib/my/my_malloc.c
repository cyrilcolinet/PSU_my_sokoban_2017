/*
** EPITECH PROJECT, 2017
** my_malloc
** File description:
** Malloc with exit when fail
*/

# include <stdlib.h>
# include "my.h"

void *my_malloc(unsigned int size)
{
	void *ptr = malloc(size);

	if (ptr == NULL) {
		my_puterr("Malloc failed. Abord.\n");
		exit(84);
	}

	return (ptr);
}
