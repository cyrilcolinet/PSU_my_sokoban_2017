/*
** EPITECH PROJECT, 2017
** my_compute_power_rec
** File description:
** Recursive function that returns the first argument raised to the power p, where p is the second argument
*/

# include "my.h"

int my_compute_power_rec(int nb, int p)
{
	if (p == 0)
		return (1);
	else if (p < 0)
		return (0);
	return (nb * my_compute_power_rec(nb, (p - 1)));
}
