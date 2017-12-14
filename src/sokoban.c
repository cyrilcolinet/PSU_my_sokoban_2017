/*
** EPITECH PROJECT, 2017
** my_sokoban
** File description:
** sokoban functions
*/

# include "my.h"
# include "sokoban.h"

void display_map(char *filename)
{
	FILE *file = fopen(filename, "r");
	char *line = NULL;
	size_t len = 0;
	ssize_t read;

	if (file == NULL) {
		my_puterr("Error while reading file.\n");
		exit(84);
	}

	while ((read = getline(&line, &len, file)) != -1) {
		printw(line);
	}
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