/*
** EPITECH PROJECT, 2018
** libmy_printf
** File description:
** falgs_string functions
*/

# include "my_printf.h"

int flag_s(va_list ap, int out, char *ptr)
{
	char *str = va_arg(ap, char *);

	if (ptr == NULL)
		return (out);

	out += my_putstr(str);
	return (out);
}

int flag_c(va_list ap, int out, char *ptr)
{
	char c = ((char) va_arg(ap, int));

	if (ptr == NULL)
		return (out);

	out += write(0, &c, 1);
	return (out);
}

int flag_S(va_list ap, int out, char *ptr)
{
	char *str = va_arg(ap, char *);

	if (ptr == NULL)
		return (out);

	while (*str) {
		if (*str < 32 || *str >= 127) {
			if (*str < 7) {
				out += my_putstr("\\00");
			} else if (*str > 7 && *str < 32) {
				out += my_putstr("\\0");
			} else if (*str >= 127) {
				out += my_putstr("\\");
			}

			out += my_put_nbr_base(*str, "01234567");
		} else {
			out += my_putchar(*str);
		}
		str++;
	}

	return (out);
}

int flag_percent(va_list ap, int out, char *ptr)
{
	if (ptr == NULL || ap == NULL)
		return (out);

	out += my_putchar('%');
	return (out);
}

int flag_m(va_list ap, int out, char *ptr)
{
	if (ptr == NULL || ap == NULL)
		return (out);

	out += my_putstr("Success");
	return (out);
}