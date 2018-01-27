/*
** EPITECH PROJECT, 2018
** my_realloc
** File description:
** my_realloc function
*/

# include <stdlib.h>
# include "my.h"

static void	my_emptystr(void *s, size_t n)
{
	char *ptr;
	size_t i;

	if (!n)
		return;
	ptr = s;
	i = 0;
	while (i < n)
		*(ptr + i++) = 0;
}

static void	*my_memalloc(size_t size)
{
	void *mem;

	if (!(mem = malloc(size)))
		return (NULL);

	my_emptystr(mem, size);
	return (mem);
}

static void	*my_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i = -1;

	while (++i < n)
		((unsigned char *)dst)[i] = ((unsigned char *)src)[i];

	return (dst);
}

char *my_realloc(void *ptr, size_t prev_size, size_t new_size)
{
	void *new;

	if (!ptr)
		return (NULL);

	if (!(new = my_memalloc(new_size))) {
		free(ptr);
		return (NULL);
	}

	my_memcpy(new, ptr, prev_size < new_size ? prev_size : new_size);
	free(ptr);
	return (new);
}