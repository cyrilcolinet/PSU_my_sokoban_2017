/*
** EPITECH PROJECT, 2018
** libmy_printf
** File description:
** my_printf functions
*/

# include "my_printf.h"

int check_match(char *ptr, param_t *param, int out, va_list ap)
{
	int i = 0;

	while (*ptr != param->flag && i < 18) {
		param++;
		i++;
	}

	if (i == 18) {
		write(0, "?.?", 3);
	} else {
		out = param->fct(ap, out, ptr);
	}

	return (out);
}

void start(char *format, param_t *param, va_list ap)
{
	char *ptr = format;
	int out = 0;

	while (*ptr) {
		if (*ptr == '%') {
			ptr++;
			out = check_match(ptr, param, out, ap);
		} else {
			out += my_putchar(*ptr);
		}

		ptr++;
	}
}

void my_printf(char *format, ...)
{
	va_list ap;
	param_t *param = malloc(sizeof(*param) * 17);
	char *flags = "disScpxXobmun%+ l";

	va_start(ap, format);

	if (param == NULL) {
		write(2, "Malloc failed. Aborded.\n", 24);
		return;
	}

	configure(param, flags);
	start(format, param, ap);
	free(param);
	va_end(ap);
}