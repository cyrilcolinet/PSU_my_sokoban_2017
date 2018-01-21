/*
** EPITECH PROJECT, 2018
** my_printf
** File description:
** my_printf functions (header file)
*/

# ifndef PRINTF_H
# define PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>

typedef int (*pf)(va_list, int, char *);

typedef struct param {
	char 	flag;
	pf 		fct;
} param_t;

int 	check_match(char *ptr, param_t *param, int out, va_list ap);
void 	start(char *format, param_t *param, va_list ap);

pf 		*flags_functions(pf **arr);
void 	configure(param_t *param, char *flags);

int 	flag_s(va_list ap, int out, char *ptr);
int 	flag_c(va_list ap, int out, char *ptr);
int 	flag_S(va_list ap, int out, char *ptr);
int 	flag_percent(va_list ap, int out, char *ptr);
int 	flag_m(va_list ap, int out, char *ptr);

int 	flag_d(va_list ap, int out, char *ptr);
int 	flag_o(va_list ap, int out, char *ptr);
int 	flag_b(va_list ap, int out, char *ptr);
int 	flag_n(va_list ap, int out, char *ptr);

int 	flag_x(va_list ap, int out, char *ptr);
int 	flag_X(va_list ap, int out, char *ptr);
int 	flag_p(va_list ap, int out, char *ptr);

int 	flag_u(va_list ap, int out, char *ptr);

int 	my_put_nbr_base(int nb, char *base);
int 	my_putchar(char c);
int 	my_putstr(char *str);
int 	my_strlen(char *str);
char 	*my_strcat(char *dest, char *src);
int 	my_put_nbr(int nb);

# endif