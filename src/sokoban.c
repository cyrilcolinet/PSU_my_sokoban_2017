/*
** EPITECH PROJECT, 2017
** my_sokoban
** File description:
** sokoban functions
*/

# include "my.h"
# include "sokoban.h"

void map_reading(char **line, size_t *len, FILE *file, ssize_t read)
{
	int x = 0, y = 0;

	while ((read = getline(line, len, file)) != -1) {
		for (x = 0; x < my_strlen(*line); x++) {
			if (*line[x] == 'P') {
				
			}
		}

		y++;
		printw(*line);
	}
}

void display_map(char *filename)
{
	FILE *file = fopen(filename, "r");
	char *line = NULL;
	size_t len = 0;
	ssize_t read = -1;

	if (file == NULL) {
		my_puterr("Error while reading file.\n");
		exit(84);
	}

	map_reading(&line, &len, file, read);
}

int sokoban_main(int ac, char **av)
{
	check_args(ac, av);
	initscr();
	display_map(av[1]);
	getch();
	endwin();

	return (0);
}