# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gejo <gejo@student.42seoul.kr>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/10 22:25:57 by gejo              #+#    #+#              #
#    Updated: 2021/07/16 12:48:11 by gejo             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

CFLAGS = -g3 -fsanitize=address -L../mlx -lmlx -framework OpenGL -framework Appkit

SRC	= ft_main.c\
	  ft_map_validation.c\
	  ft_map_checker.c\
	  ft_load_texture.c\
	  ft_draw_screen.c\
	  ft_draw_sprite.c\
	  ft_draw_exit.c\
	  ft_draw_player.c\
	  ft_move.c\
	  ft_string.c\
	  ft_enemy.c\
	  ft_move_enemy.c\
	  mlibft.c\
	  ft_free.c\
	  ft_error.c

OBJ = ft_main.o\
	  ft_map_validation.o\
	  ft_map_checker.o\
	  ft_load_texture.o\
	  ft_draw_screen.o\
	  ft_draw_sprite.o\
	  ft_draw_exit.o\
	  ft_draw_player.o\
	  ft_move.o\
	  ft_string.o\
	  ft_enemy.o\
	  ft_move_enemy.o\
	  mlibft.o\
	  ft_free.o\
	  ft_error.o

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
