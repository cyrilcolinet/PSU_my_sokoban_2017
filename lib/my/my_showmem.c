/*
** EPITECH PROJECT, 2017
** my_showmem
** File description:
** Display memory dumpl
*/

# include "my.h"

static int digit_count(int nbr, int base)
{
	int result = 0;
	if (nbr == 0)
		return (1);
	while (nbr != 0) {
		nbr /= base;
		result++;
	}
	return (result);
}

static void print_hex(int nbr, int char_count)
{
	char *hex_base = "0123456789abcdef";
	int i = 0;
	while (i < (char_count - digit_count(nbr, 16))) {
		my_putchar('0');
		i++;
	}
	if (nbr < 0)
		nbr = -nbr;
	my_putnbr_base(nbr, hex_base);
}

static void print_hex_str(char *beg, char *end)
{
	int i = 0;
	int char_count = 0;
	while (i < 16 && &beg[i] < end) {
		print_hex(beg[i], 2);
		if (i % 2 != 0) {
			my_putchar(' ');
			char_count++;
		}
		i++;
		char_count += 2;
	}
	while (char_count < 41) {
		my_putchar(' ');
		char_count++;
	}
}

void my_showmem(char *str, int size)
{
	char *address = str;
	int i;
	while (address < str + size) {
		print_hex(address - str, 8);
		my_putchar(':');
		my_putchar(' ');
		print_hex_str(address, str + size);
		i = 0;
		while (&address[i] < address + 16 && &address[i] < str + size) {
			if (address[i] > 31 && address[i] < 127)
				my_putchar(address[i]);
			else
				my_putchar('.');
			i++;
		}
		address += 16;
		my_putchar('\n');
	}
}
