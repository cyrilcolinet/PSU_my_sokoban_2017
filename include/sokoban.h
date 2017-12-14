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
# include <termios.h>

typedef struct termios term_t;

int 		sokoban_main(int ac, char **av);

void 		check_args(int ac, char **av);

# endif