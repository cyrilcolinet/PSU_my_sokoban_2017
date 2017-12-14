/*
** EPITECH PROJECT, 2017
** my_is_prime
** File description:
** Check if numer given as parameter is prime
*/

# include "my.h"

int my_is_prime(int nbr)
{
	int i = 2;
	while (i <= nbr / 2) {
		if (nbr % i == 0)
			return (0);
		i++;
	}
	return (1);
}
