/*
** EPITECH PROJECT, 2017
** my_puterr
** File description:
** Display error
*/

# include <unistd.h>
# include "my.h"

void my_puterr(char *str)
{
	write(2, str, my_strlen(str));
}
