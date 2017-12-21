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
	int box = 0, goal = 0;

	if (param->objects_len < 3 || param->width < 3 || param->heigth < 4)
		quit = true;

	for (int i = 0; i <= param->objects_len; i++)
		if (param->objects[i].type == t_tub) box++;
		else if (param->objects[i].type == t_goal) goal++;

	if (box != goal) {
		quit = true;
		err = "Box and goals must be the same.\n";
	}

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