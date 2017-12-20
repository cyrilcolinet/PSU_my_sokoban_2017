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

	return (param);
}

void add_object(param_t *param, type_e type, int x, int y)
{
	object_t *obj = my_malloc(sizeof(*obj));

	obj->type = type;
	obj->x = x;
	obj->y = y;
	param->objects[param->objects_len] = *obj;
	param->objects_len++;
	free(obj);
}

void destroy(param_t *param)
{
	free(param->objects);
	free(param);
}

void display_help(void)
{
	my_putstr("USAGE:\n");
	my_putstr("\t./my_sokoban [-h] <map>\n\n");
	my_putstr("DESCRIPTION:\n");
	my_putstr("\t-h\tDisplay help page (this page)\n");
	my_putstr("\t<map>\tFile thats represents wareouse map\n");
}

void check_args(int ac, char **av)
{
	if (ac != 2) {
		my_puterr("Usage: ./my_sokoban [-h] <map>\n");
		exit(84);
	} else {
		if (av[1][0] == '-' && av[1][1] == 'h') {
			display_help();
			exit(0);
		}
	}
}