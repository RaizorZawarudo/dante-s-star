##
## EPITECH PROJECT, 2021
## makefile
## File description:
## .
##

SRC	=	main.c	\
		load_file.c\
		move.c\
		tools.c\
		./source/my_int_to_str.c \
		./source/my_putchar.c \
		./source/my_putstr.c \
		./source/my_str_to_int.c \
		./source/my_strcmp.c \
		./source/my_strcpy.c \
		./source/my_strlen.c \
		./source/my_putchar_err.c \
		./source/my_putstr_err.c \
		./source/my_str_isnum.c

NAME	=	solver

INC	=	-I include/

all:	$(NAME) clean

$(NAME):
	gcc $(SRC) -o $(NAME) $(LMY) $(INC) -g3 -Wall -Wextra -W

clean:
	rm -f *.o

fclean:	clean
	rm -f $(NAME)

re:	fclean all