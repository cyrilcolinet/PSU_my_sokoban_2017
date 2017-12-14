/*
** EPITECH PROJECT, 2017
** my_compute_square_root
** File description:
** Function that return the square root of the number given as argument. If the square root is not a whole number, the function should return 0
*/

# include "my.h"

int my_compute_square_root(int nb)
{
	int loop = 0;
	for (; (loop * loop) != nb; loop++) {
		if ((loop * loop) > nb)
			return (0);
	}
	return ((loop < 0) ? 1 : loop);
}
