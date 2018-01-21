/*
** EPITECH PROJECT, 2017
** my_sokoban
** File description:
** map_utils functions
*/

# include "my.h"
# include "sokoban.h"

void check_map_format(param_t *param)
{
	bool quit = false;
	char *err = NULL;
//	int box = 0, goal = 0;

	if (param->objects_len < 3 || param->width < 3 || param->heigth < 4)
		quit = true;

/*	for (int i = 0; i <= param->objects_len; i++)
		if (param->objects[i].type == t_tub) box++;
		else if (param->objects[i].type == t_goal) goal++;

	if (box != goal) {
		quit = true;
		err = "Box and goals must be the same.\n";
	}
*/

	if (quit) {
		destroy(param);
		my_puterr("Invalid map format. ", false);
		my_puterr(err, true);
	}
}

void print_centered(char *line)
{
    for (int i = 0; i < (132 - my_strlen(line)) / 2; i++)
        printw(" ");

    printw("%s", line);
}

void duplicate_original_map(param_t *param, char **map)
{
	char **ori = my_malloc(sizeof(*ori) * param->heigth);

	for (int i = 0; i < param->heigth; i++) {
		ori[i] = my_strdup(map[i]);
	}

	param->original = ori;
}

char **get_map_content(param_t *param, char *filename)
{
	int line = 0;
	char **map = my_malloc(sizeof(*map) * param->heigth);
	fileopt_t *fopt = get_file(param, filename);

	while ((fopt->read = getline(&fopt->line, &fopt->len, fopt->file)) != -1) {
		map[line++] = my_strdup(fopt->line);
	}

	fclose(fopt->file);
	free(fopt);
	duplicate_original_map(param, map);
	return (map);
}

int *get_player_position(param_t *param)
{
	int *pos = my_malloc(sizeof(*pos) * 2);

	for (int row = 0; row < param->heigth; row++)
		for (int col = 0; col < my_strlen(param->map[row]); col++)
			if (param->map[row][col] == 'P') {
				pos[0] = col;
				pos[1] = row;
				return (pos);
			}

	my_puterr("Unable to get player position.\n", true);
	return (NULL);
}
