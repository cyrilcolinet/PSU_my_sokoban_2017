/*
** EPITECH PROJECT, 2017
** my_sokoban
** File description:
** sokoban functions (header file)
*/

# ifndef SOKOBAN_H
# define SOKOBAN_H

# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>
# include <ncurses.h>
# include <stdlib.h>

typedef enum type {
	tub, player, goal
} type_e;

typedef struct object {
	type_e 		type;
	int 		x;
	int 		y;
} object_t;

typedef struct param {
	int 		objects_len;
	object_t 	*objects;
} param_t;

void 		map_reading(char **line, size_t *len, FILE *file, ssize_t read);
int 		sokoban_main(int ac, char **av);
void 		display_map(char *filename);

param_t 	*init_parameters(void);
void 		add_object(param_t *param, type_e type, int x, int y);
void 		destroy(param_t *param);
void 		display_help(void);
void 		check_args(int ac, char **av);

# endif