# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gejo <gejo@student.42seoul.kr>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/10 22:25:57 by gejo              #+#    #+#              #
#    Updated: 2021/07/14 19:43:41 by gejo             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

CFLAGS = -L../mlx -lmlx -framework OpenGL -framework Appkit

SRC = parsing.c\
	  ft_move.c\
	  ft_string.c\
	  ft_enemy.c\
	  ft_move_enemy.c\
	  mlibft.c\
	  ft_free.c

OBJ = parsing.o\
	  ft_move.o\
	  ft_string.o\
	  ft_enemy.o\
	  ft_move_enemy.o\
	  mlibft.o\
	  ft_free.o

all : $(NAME)

$(NAME) : $(OBJ)
	gcc $(CFLAGS) -o $(NAME) $(OBJ)

$(OBJ) : $(SRC)
	gcc -c $(SRC)

clean :
	rm -f $(OBJ)

fclean : clean
	rm -f $(NAME)

re : fclean all
