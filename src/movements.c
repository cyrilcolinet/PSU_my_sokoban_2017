/*
** EPITECH PROJECT, 2017
** my_sokoban
** File description:
** movements functions
*/

# include "my.h"
# include "sokoban.h"

void movement_management(param_t *param, int key)
{
	int *pos = get_player_position(param);

	if (key == KEY_UP) move_top(param, pos);
	else if (key == KEY_LEFT) move_left(param, pos);
	else if (key =='q') param->leaved = true;
}

void move_right(param_t *param, int *pos)
{
	char *map = param->map[pos[1]];
	char *ori = param->original[pos[1]];

	if (pos[0] > 0 && map[(pos[0] + 1)] == '#')
		return;

	if (map[(pos[0] + 1)] == 'X') {
		if (map[(pos[0] + 2)] != '#' && map[(pos[0] + 2)] != 'X') {
			param->map[pos[1]][(pos[0] + 1)] = 'P';

			if (ori[pos[0]] == 'O') param->map[pos[1]][pos[0]] = 'O';
			else param->map[pos[1]][pos[0]] = ' ';

			param->map[pos[1]][(pos[0] + 2)] = 'X';
		}
	} else {
		param->map[pos[1]][(pos[0] + 1)] = 'P';

		if (ori[pos[0]] == 'O') param->map[pos[1]][pos[0]] = 'O';
		else param->map[pos[1]][pos[0]] = ' ';
	}
}

void move_left(param_t *param, int *pos)
{
	char *map = param->map[pos[1]];
	char *ori = param->original[pos[1]];

	if (pos[0] > 0 && map[(pos[0] - 1)] == '#')
		return;

	if (map[(pos[0] - 1)] == 'X') {
		if (map[(pos[0] - 2)] != '#' && map[(pos[0] - 2)] != 'X') {
			param->map[pos[1]][(pos[0] - 1)] = 'P';

			if (ori[pos[0]] == 'O') param->map[pos[1]][pos[0]] = 'O';
			else param->map[pos[1]][pos[0]] = ' ';

			param->map[pos[1]][(pos[0] - 2)] = 'X';
		}
	} else {
		param->map[pos[1]][(pos[0] - 1)] = 'P';

		if (ori[pos[0]] == 'O') param->map[pos[1]][pos[0]] = 'O';
		else param->map[pos[1]][pos[0]] = ' ';
	}
}

void move_top(param_t *param, int *pos)
{
	char **map = param->map;
	char *ori = param->original[pos[1]];

	if (map[(pos[1] - 1)][pos[0]] == '#')
		return;

	if (map[(pos[1] - 1)][pos[0]] == 'X') {
		if (map[(pos[1] - 2)][pos[0]] != '#' && map[(pos[0] - 2)][pos[0]] != 'X') {
			param->map[(pos[1] - 1)][pos[0]] = 'P';

			if (ori[pos[1]] == 'O') param->map[pos[1]][pos[0]] = 'O';
			else param->map[pos[1]][pos[0]] = ' ';

			param->map[(pos[1] - 2)][pos[0]] = 'X';
		}
	} else {
		param->map[(pos[1] - 1)][pos[0]] = 'P';

		if (ori[pos[1]] == 'O') param->map[pos[1]][pos[0]] = 'O';
		else param->map[pos[1]][pos[0]] = ' ';
	}
}

void move_bottom(param_t *param, int *pos)
{

}