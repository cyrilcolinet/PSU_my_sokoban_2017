/*
** EPITECH PROJECT, 2017
** my_sokoban
** File description:
** utils functions
*/

# include "my.h"
# include "sokoban.h"

param_t *init_parameters(void)
{
	param_t *param = my_malloc(sizeof(*param));

	param->objects = NULL;
	param->objects_len = 0;
	param->heigth = 0;
	param->width = 0;
	param->objects_off = 0;
	param->map = NULL;
	param->leaved = false;
	param->original = NULL;
	param->leaved_reason = NULL;

	return (param);
}

void add_object(param_t *param, type_e type, int x, int y)
{
	object_t *obj = param->objects;

	obj[param->objects_off].type = type;
	obj[param->objects_off].x = x;
	obj[param->objects_off].y = y;
	param->objects_off += 1;
	param->objects = obj;
}

void destroy(param_t *param)
{
	endwin();

	if (param->objects != NULL)
		free(param->objects);

	my_freetab(param->map);
	my_freetab(param->original);

	if (param->leaved_reason != NULL) {
		my_putstr(param->leaved_reason);
		my_putchar('\n');
	}

	free(param);
}

void display_help(void)
{
	my_putstr("USAGE:\n");
	my_putstr("\t./my_sokoban [-h] <map>\n\n");
	my_putstr("DESCRIPTION:\n");
	my_putstr("\t-h\tDisplay help page (this page)\n");
	my_putstr("\t<map>\tFile thats represents warehouse map\n");
}

void check_args(param_t *param, int ac, char **av)
{
	if (ac != 2) {
		destroy(param);
		my_puterr("Usage: ./my_sokoban [-h] <map>\n", true);
	} else {
		if (av[1][0] == '-' && av[1][1] == 'h') {
			display_help();
			exit(0);
		}
	}
}