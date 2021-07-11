# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gejo <gejo@student.42seoul.kr>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/10 22:25:57 by gejo              #+#    #+#              #
#    Updated: 2021/07/11 23:11:59 by gejo             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

CFLAGS = -g3 -fsanitize=address -L../mlx -lmlx -framework OpenGL -framework Appkit

SRC = test.c\
	  mlibft.c

OBJ = test.o\
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
