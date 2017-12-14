/*
** EPITECH PROJECT, 2017
** my_is_prime_sup
** File description:
** Return nb if the number is prime, and the closest prime number otherwise
*/

# include "my.h"

int my_find_prime_sup(int nb)
{
	int i = nb + 1;
	while (!my_is_prime(i))
		i++;
	return (i);
}
