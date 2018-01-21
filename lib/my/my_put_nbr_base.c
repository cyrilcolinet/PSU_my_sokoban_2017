/*
** EPITECH PROJECT, 2017
** my_put_nbr_base
** File description:
** my_putnbr_base function
*/

# include "my.h"

void my_put_nbr_base(int nbr, char *base)
{
	int size = 0;
	int mod = 0;
	while (base[size] != '\0')
		size += 1;
	if (size <= 1)
		return;
	mod %= size;
	if (mod < 0)
		mod = -mod;
	if (nbr / size == 0) {
		if (nbr < 0)
			my_putchar('-');
		my_putchar(base[mod]);
		return;
	}
	my_put_nbr_base(nbr / size, base);
	my_putchar(base[mod]);
}