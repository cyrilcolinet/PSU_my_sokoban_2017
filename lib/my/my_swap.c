/*
** EPITECH PROJECT, 2017
** my_swap
** File description:
** Swap two numbers
*/

# include "my.h"

void my_swap(int *p1, int *p2)
{
	int tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;
}
