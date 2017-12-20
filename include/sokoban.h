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

typedef struct file_opt {
	FILE 	*file;
	char 	*line;
	size_t 	len;
	ssize_t read;
} fileopt_t;

typedef struct object {
	type_e 		type;
	int 		x;
	int 		y;
} object_t;

typedef struct param {
	int 		objects_len;
	object_t 	*objects;
} param_t;

void 		map_reading(param_t *param, char *line, int y);
fileopt_t 	*get_file(param_t *param, char *file);
void 		count_objects(param_t *param, char *line);
int 		sokoban_main(int ac, char **av);
void 		display_map(param_t *param, char *filename);

param_t 	*init_parameters(void);
void 		add_object(param_t *param, type_e type, int x, int y);
void 		destroy(param_t *param);
void 		display_help(void);
void 		check_args(param_t *param, int ac, char **av);

# endif