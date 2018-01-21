/*
** EPITECH PROJECT, 2018
** libmy_printf
** File description:
** print_hexadecimal functions
*/

# include "my_printf.h"

int flag_x(va_list ap, int out, char *ptr)
{
	unsigned int nb = va_arg(ap, unsigned int);

	if (ptr == NULL)
		return (out);

	if (((int) nb) < 0) {
		out += write(0, "ffffff", 6);
	} else {
		out += my_put_nbr_base(nb, "0123456789abcdef");
	}

	return (out);
}

int flag_X(va_list ap, int out, char *ptr)
{
	unsigned int nb = va_arg(ap, unsigned int);

	if (ptr == NULL)
		return (out);

	if (((int) nb) < 0) {
		out += write(0, "FFFFFF", 6);
	} else {
		out += my_put_nbr_base(nb, "0123456789ABCDEF");
	}

	return (out);
}

/*int flag_p(va_list ap, int out, char *ptr)
{
	//void *str = va_arg(ap, void *);

	if (ptr == NULL)
		return (out);

	out += write(0, "0x7fff", 6);
	out += my_put_nbr_base(10, "0123456789abcdef");
	return (out);
}*/