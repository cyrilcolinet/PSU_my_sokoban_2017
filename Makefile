##
## EPITECH PROJECT, 2017
## my_sokoban
## File description:
## Makefile with build project rule and units tests
##

.PHONY			: all, fclean, clean, re, tests_run, library

NAME 			= my_sokoban

SRC 			= src/sokoban.c 			\
				  src/main.c 				\
				  src/utils.c 				\
				  src/map_utils.c 			\
				  src/game.c 				\
				  src/movements.c

CFLAGS 			= -Wall -Wextra -I./include --coverage

EXTRA_FLAGS 	= -L./lib/ -lmy -g3 -lncurses

CC 				= gcc

RM 				= rm -f

OBJ 			= $(SRC:.c=.o)

all: 			library $(NAME)

$(NAME):		$(OBJ)
				$(CC) $(CFLAGS) $(EXTRA_FLAGS) $(OBJ) ./lib/my/*.o -o $(NAME)

library:
				make -C ./lib

clean:
				$(RM) $(OBJ)
				$(RM) vgcore.*
				make clean -C ./lib

fclean: 		clean
				$(RM) $(NAME)
				make fclean -C ./lib
				rm -rf src/*.gc*

re: 			fclean all

tests_run:		re
				@echo "Running units tests..."

