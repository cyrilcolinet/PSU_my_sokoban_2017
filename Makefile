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
				  src/utils.c

CFLAGS 			= -Wall -Wextra -Werror -I./include -g3

EXTRA_FLAGS 	= -L./lib/ -lmy -g3

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

fclean: 		clean
				$(RM) $(NAME)
				make fclean -C ./lib

re: 			fclean all

tests_run:		re
				@echo "Running units tests..."

