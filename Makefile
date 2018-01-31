##
## EPITECH PROJECT, 2017
## my_sokoban
## File description:
## Makefile with build project rule and units tests
##

## Color variables

SUCCESS			= /bin/echo -e "\x1b[1m\x1b[33m\#\#\x1b[32m $1\x1b[0m"

## Compilation variables

NAME 			= my_sokoban

SRCDIR 			= ./src/

SRCNAMES 		= main.c 			\
				  game.c 			\
				  map_utils.c 		\
				  movements.c 		\
				  sokoban.c 		\
				  utils.c

SRC 			= $(addprefix $(SRCDIR), $(SRCNAMES))

INC 			= ./include

BUILDDIR 		= ./build/

BUILDSUBDIR 	= $(shell cd $(SRCDIR) && find . -mindepth 1 -type d -printf '%p\n')

BUILDOBJS 		= $(addprefix $(BUILDDIR), $(SRCNAMES:.c=.o))

LIBDIR 			= ./lib/

LIBMY 			= ./lib/libmy.a

CC 				= gcc

DEBUG 			= -g3

CFLAGS 			= -Wall -Wextra -I$(INC) $(DEBUG) --coverage

OBJ 			= $($SRC:.c=.o)

## Rules

all: 			$(BUILDDIR) $(LIBMY) $(NAME)
				@$(call SUCCESS, "Project successfully compiled.")
				@clear

$(BUILDDIR):
				mkdir -p $(BUILDDIR)
				$(foreach subdir, $(BUILDSUBDIR), $(shell mkdir -p build/$(subdir)))

$(BUILDDIR)%.o:	$(SRCDIR)%.c
				$(CC) $(CFLAGS)   -c -o $@ $<

$(NAME): 		$(BUILDOBJS)
				$(CC) $(CFLAGS) -L$(LIBDIR) -lmy -lc_graph_prog -o $(NAME) $(BUILDOBJS) $(LIBDIR)/my/*.o $(LIBFT)
				@$(call SUCCESS, "All objects files successfully regrouped in ./$(NAME) binary file.")

$(LIBMY):
				make -C $(LIBDIR)

clean:
				rm -rf $(BUILDDIR)
				find -name '*.gc*' -delete -or -name 'vgcore.*' -delete
				make -C $(LIBDIR) clean
				@$(call SUCCESS, "Project fully cleaned.")

fclean: 		clean
				rm -rf $(NAME)
				make -C $(LIBDIR) fclean

re: 			fclean all

# Just in case those files exist in the root dir
.PHONY			: all fclean clean re
