/*
** EPITECH PROJECT, 2018
** my_getline
** File description:
** get_line functions
*/

# include <stdlib.h>
# include <unistd.h>
# include "my.h"

static int get_character(int fdesc, char *str)
{
	static int off = 0;
	static char buff[READ_SIZE];
	static int reader = READ_SIZE;

	if (off >= reader || off == 0) {
		off = 0;

		if ((reader = read(fdesc, buff, READ_SIZE)) == 0)
			return (0);
	}
	if (reader == 0) {
		*str = 0;
		off = -1;
	} else {
		if (buff[off] == '\n' || buff[off] == '\0') *str = 0;
		else *str = buff[off];
	}

	off++;
	return (reader);
}

static char *return_freed(char *ptr, char *ret)
{
	if (ptr != NULL)
		free(ptr);

	return (ret);
}

char *my_getline(int fdesc)
{
	char *line = malloc(sizeof(*line) * (READ_SIZE + 1));
	int i = 0;
	int reader = get_character(fdesc, &line[i]);

	if (reader == 0 || line == NULL)
		return (return_freed(line, NULL));

	while (line[i]) {
		if (i % READ_SIZE == 0) {
			line = my_realloc(line, i + READ_SIZE + 1);

			if (line == NULL)
				return (return_freed(line, NULL));
		}

		reader = get_character(fdesc, &line[++i]);
	}

	line[++i] = 0;
	return (line);
}