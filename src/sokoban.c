/*
** EPITECH PROJECT, 2017
** my_sokoban
** File description:
** sokoban functions
*/

# include "my.h"
# include "sokoban.h"

void map_reading(param_t *param, char *line, int y)
{
	for (int x = 1; x <= my_strlen(line); x++) {
		if (line[x] == 'P') {
			add_object(param, t_player, x, y);
		} else if (line[x] == 'X') {
			add_object(param, t_tub, x, y);
		} else if (line[x] == 'O') {
			add_object(param, t_goal, x, y);
		}
	}
}

fileopt_t *get_file(param_t *param, char *file)
{
	fileopt_t *fopt = my_malloc(sizeof(*fopt));

	fopt->file = fopen(file, "r");
	fopt->line = NULL;
	fopt->len = 0;
	fopt->read = -1;

	if (fopt->file == NULL) {
		destroy(param);
		my_puterr("Error while reading file.\n", true);
	}

	return (fopt);
}

void count_objects(param_t *param, char *line)
{
	for (int x = 0; x <= my_strlen(line); x++) {
		if (line[x] == 'P' || line[x] == 'O' || line[x] == 'X') {
			param->objects_len += 1;
		}

		param->width = x;
	}
}

void configure_map(param_t *param, char *filename)
{
	int y = 0;
	fileopt_t *fopt = get_file(param, filename);

	while ((fopt->read = getline(&fopt->line, &fopt->len, fopt->file)) != -1)
		count_objects(param, fopt->line);

	fclose(fopt->file);
	free(fopt);
	fopt = get_file(param, filename);
	param->objects = my_malloc(sizeof(*param->objects) * param->objects_len);

	while ((fopt->read = getline(&fopt->line, &fopt->len, fopt->file)) != -1)
		map_reading(param, fopt->line, y++);

	param->heigth = y;
	fclose(fopt->file);
	free(fopt);
	check_map_format(param);
	param->map = get_map_content(param, filename);
}

int sokoban_main(int ac, char **av)
{
	param_t *param = init_parameters();

	check_args(param, ac, av);
	initscr();
	configure_map(param, av[1]);
	keypad(stdscr, true);
	noecho();
	curs_set(0);
	game(param);
	destroy(param);

	return (0);
}