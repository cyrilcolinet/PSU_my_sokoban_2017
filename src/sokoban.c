/*
** EPITECH PROJECT, 2017
** my_sokoban
** File description:
** sokoban functions
*/

# include "my.h"
# include "sokoban.h"

void map_reading(param_t *param, size_t len, char *line, int y)
{
	for (int x = 0; x <= len; x++)
		if (line[x] == 'P' || line[x] == 'O' || line[x] == 'X')
			param->objects_len++;

	for (int x = 0; x <= len; x++) {
		if (line[x] == 'P') add_object(param, player, x, y);
		if (line[x] == 'X') add_object(param, tub, x, y);
		if (line[x] == 'O') add_object(param, goal, x, y);
	}

	printw(line);
}

void display_map(param_t *param, char *filename)
{
	FILE *file = fopen(filename, "r");
	char *line = NULL;
	size_t len = 0;
	ssize_t read = -1;
	int y = 0;

	if (file == NULL)
		my_puterr("Error while reading file.\n", true);

	while ((read = getline(&line, &len, file)) != -1)
		map_reading(param, len, line, y++);
}

int sokoban_main(int ac, char **av)
{
	param_t *param = init_parameters();

	check_args(ac, av);
	initscr();
	display_map(param, av[1]);
	getch();
	endwin();
	destroy(param);

	return (0);
}