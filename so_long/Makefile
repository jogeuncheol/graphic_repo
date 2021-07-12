# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gejo <gejo@student.42seoul.kr>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/10 22:25:57 by gejo              #+#    #+#              #
#    Updated: 2021/07/12 21:03:37 by gejo             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

CFLAGS = -g3 -fsanitize=address -L../mlx -lmlx -framework OpenGL -framework Appkit

SRC = parsing.c\
	  mlibft.c

OBJ = parsing.o\
	  mlibft.o

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
