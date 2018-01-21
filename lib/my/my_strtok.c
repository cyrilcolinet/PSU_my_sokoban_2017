/*
** EPITECH PROJECT, 2017
** my_strtok
** File description:
** cut fonction with delim
*/

# include <stdbool.h>
# include "my.h"

static bool cts(char c, char *str)
{
	int i;

	if (!c)
		return (true);

	for (i = 0; str[i]; i++) {
		if (str[i] == c)
			return (true);
	}

	return (false);
}

static int cnt_parts(char *str, char *delim)
{
	int count = 0;
	int i;

	for (i = 0; str[i]; i++) {
		if (!cts(str[i], delim) && cts(str[i + 1], delim))
			count++;
	}

	return (count);
}

char **my_strtok(char *str, char *delim)
{
	int j = 0, k = 0, i;
	char **ret = my_malloc(sizeof(*ret) * (cnt_parts(str, delim) + 1));

	for (i = 0; str[i]; i++) {
		if (!cts(str[i], delim))
			k++;

		if (!cts(str[i], delim) &&
			cts(str[i + 1], delim)) {
			ret[j] = my_malloc(sizeof(**ret) * (k + 1));
			ret[j][0] = 0;
			ret[j] = my_strncat(ret[j], &str[i - (k - 1)], k);
			k = 0;
			j++;
		}
	}

	return (ret);
}