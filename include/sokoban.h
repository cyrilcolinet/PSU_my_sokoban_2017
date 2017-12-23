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

typedef struct winsize winsize_t;

typedef enum type {
	t_tub, t_player, t_goal
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
	int 		objects_off;
	object_t 	*objects;
	int 		heigth;
	int 		width;
	char 		**original;
	char 		**map;
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

void 		check_map_format(param_t *param);
void 		print_centered(char *line);
char 		**get_map_content(param_t *param, char *file);

void 		movement_management(param_t *param);
void 		move_right(param_t *param);
void 		move_left(param_t *param);
void 		move_top(param_t *param);
void 		move_bottom(param_t *param);


# endif