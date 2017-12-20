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
	if (param->objects_len < 3)
		my_puterr("Invalid map format.\n", true);

	if (param->width < 3 || param->heigth < 4)
		my_puterr("Map must be 3x4 or grater.\n", true);
}