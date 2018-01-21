/*
** EPITECH PROJECT, 2018
** libmy_printf
** File description:
** flags_number functions
*/

# include "my_printf.h"

int flag_d(va_list ap, int out, char *ptr)
{
	int nb = va_arg(ap, int);

	if (*ptr == '+') {
		if (nb >= 0)
			out += my_putchar('+');
	} else if (*ptr == ' ') {
		out += my_putchar(' ');
	}

	out += my_put_nbr(nb);
	return (out);
}

int flag_o(va_list ap, int out, char *ptr)
{
	int nb = va_arg(ap, unsigned int);

	if (ptr == NULL)
		return (out);

	out += my_put_nbr_base(nb, "01234567");
	return (out);
}

int flag_b(va_list ap, int out, char *ptr)
{
	int nb = va_arg(ap, int);

	if (ptr == NULL)
		return (out);

	out += my_put_nbr_base(nb, "01");
	return (out);
}

int flag_n(va_list ap, int out, char *ptr)
{
	int *nb = va_arg(ap, int *);

	if (ptr == NULL)
		return (out);

	*nb = out;
	return (0);
}