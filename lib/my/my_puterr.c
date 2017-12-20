/*
** EPITECH PROJECT, 2017
** my_puterr
** File description:
** Display error
*/

# include <stdbool.h>
# include <unistd.h>
# include <stdlib.h>
# include "my.h"

void my_puterr(char *str, bool close)
{
	write(2, str, my_strlen(str));

	if (close)
		exit(84);
}
