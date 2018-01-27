/*
** EPITECH PROJECT, 2018
** my_library
** File description:
** my_free function
*/

# include <stdlib.h>
# include "my.h"

void my_free(void **ptr) {
	free(*ptr);

	*ptr = NULL;
}