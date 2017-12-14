##
## EPITECH PROJECT, 2017
## libmy
## File description:
## Makefile libmy
##

.PHONY				: all, clean, fclean, re

NAME 				= libmy.a

SRC 				= my_atoi.c 					\
					  my_compute_power_rec.c 		\
					  my_putnbr_base.c 				\
					  my_compute_square_root.c 		\
					  my_is_prime.c 				\
					  my_find_prime_sup.c 			\
					  my_getnbr.c 					\
					  my_isneg.c 					\
					  my_malloc.c 					\
					  my_put_nbr.c 					\
					  my_putchar.c 					\
					  my_puterr.c 					\
					  my_putstr.c 					\
					  my_revstr.c 					\
					  my_show_word_array.c 			\
					  my_showmem.c 					\
					  my_showstr.c 					\
					  my_sort_int_array.c 			\
					  my_str_isalpha.c 				\
					  my_str_islower.c 				\
					  my_str_isnum.c 				\
					  my_str_isprintable.c 			\
					  my_str_isupper.c 				\
					  my_str_to_word_array.c 		\
					  my_strcapitalize.c 			\
					  my_strcat.c 					\
					  my_strcmp.c 					\
					  my_strcpy.c 					\
					  my_strdup.c 					\
					  my_strlen.c 					\
					  my_strlowcase.c 				\
					  my_strncat.c 					\
					  my_strncpy.c 					\
					  my_strstr.c 					\
					  my_strtok.c 					\
					  my_strupcase.c 				\
					  my_swap.c 					\
					  my_trim.c 

CFLAGS 				= -Wall -Wextra -Werror -I./include

CC					= gcc

AR 					= ar rc

CP 					= cp

RM 					= rm -f

INCLUDE 			= ./include

REMOTE_INCLUDE 		= ../../include/

INCLUDE_FILE		= my.h

OBJ 				= $(SRC:.c=.o)

all:				$(NAME)
					$(CP) $(NAME) ../$(NAME)
					$(CP) $(INCLUDE)/$(INCLUDE_FILE) $(REMOTE_INCLUDE)

$(NAME):			$(OBJ)
					$(AR) $(NAME) $(OBJ)

clean:
					$(RM) $(OBJ)

fclean: 			clean
					$(RM) ../$(NAME)
					$(RM) $(NAME)
					$(RM) $(REMOTE_INCLUDE)$(INCLUDE_FILE)

re: 				fclean all