/*
** EPITECH PROJECT, 2017
** my_sokoban
** File description:
** game fuctions
*/

# include "my.h"
# include "sokoban.h"

void display_map_content(param_t *param)
{
	clear();

	for (int i = 0; i < param->heigth; i++)
		printw(param->map[i]);

	refresh();
}

bool check_terminated_game(param_t *param)
{
	char **ori = param->original;

	for (int row = 0; row < param->heigth; row++) {
		for (int col = 0; param->map[row][col]; col++) {
			if (ori[row][col] == 'O' && param->map[row][col] != 'X') {
				param->leaved_reason = "Vous avez gagné ! Bravoooo !";
				return (false);
			}
		}
	}

	return (true);
}

bool check_blocked_game(param_t *param)
{
	char **map = param->map;
	char **ori = param->original;

	for (int i = 0; i < param->heigth; i++)
		for (int j = 0; j < my_strlen(map[i]); j++)
			if (map[i][j] == 'X' && ori[i][j] != 'O') {
				if (map[i + 1][j] == '#' || map[i - 1][j] == '#') {
					if (map[i][j + 1] == '#' || map[i][j - 1] == '#') {
						param->leaved_reason = "Vous avez perdu !";
						return (true);
					}
				} else if (map[i][j + 1] == '#' || map[i][j + 1] == '#') {
					if (map[i + 1][j] == '#' || map[i - 1][j] == '#') {
						param->leaved_reason = "Vous avez perdu !";
						return (true);
					}
				}
			}

	return (false);
}

void game(param_t *param)
{
	int key = 0;
	
	while (!check_terminated_game(param) && !check_blocked_game(param) && !param->leaved) {
		display_map_content(param);
		key = getch();
		movement_management(param, key);
	}

	display_map_content(param);
}