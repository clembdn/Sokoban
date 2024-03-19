##
## EPITECH PROJECT, 2023
## makefile
## File description:
## makefile_lib
##

SRC	=	src/check.c 		\
		src/display.c 		\
		src/move.c 			\
		src/xy_fonctions.c 	\
		src/main.c


OBJ	=	$(SRC:.c=.o)

NAME	=	my_sokoban

all:		$(NAME)

$(NAME): 	$(OBJ)
			gcc -o $(NAME) $(OBJ) -g3 -lncurses -I ./include/

clean:
		rm -rf $(OBJ)

fclean: clean
		rm -f $(NAME)

re:		fclean all
