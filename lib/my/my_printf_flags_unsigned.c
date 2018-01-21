/*
** EPITECH PROJECT, 2018
** libmy_printf
** File description:
** flags_unsigned functions
*/

# include "my_printf.h"

int flag_u(va_list ap, int out, char *ptr)
{
	unsigned int nb = va_arg(ap, unsigned int);

	if (ptr == NULL)
		return (out);

	out += my_put_nbr(nb);
	return (out);
}