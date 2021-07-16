# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gejo <gejo@student.42seoul.kr>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/10 22:25:57 by gejo              #+#    #+#              #
#    Updated: 2021/07/16 17:06:27 by gejo             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

CFLAGS = -g3 -fsanitize=address -L../mlx -lmlx -framework OpenGL -framework Appkit

INCLUDE = include

SRC_DIR = srcs

SRC_B_DIR = srcs_b

BONUS_HIDE = .bonus

SRC	= $(SRC_DIR)/ft_main.c\
	  $(SRC_DIR)/ft_map_validation.c\
	  $(SRC_DIR)/ft_map_checker.c\
	  $(SRC_DIR)/ft_set_game.c\
	  $(SRC_DIR)/ft_load_texture.c\
	  $(SRC_DIR)/ft_init_game.c\
	  $(SRC_DIR)/ft_draw_screen.c\
	  $(SRC_DIR)/ft_draw_sprite.c\
	  $(SRC_DIR)/ft_draw_exit.c\
	  $(SRC_DIR)/ft_draw_player.c\
	  $(SRC_DIR)/ft_draw_enemy.c\
	  $(SRC_DIR)/ft_game_status.c\
	  $(SRC_DIR)/ft_move.c\
	  $(SRC_DIR)/ft_string.c\
	  $(SRC_DIR)/ft_enemy.c\
	  $(SRC_DIR)/ft_move_enemy.c\
	  $(SRC_DIR)/mlibft.c\
	  $(SRC_DIR)/ft_free.c\
	  $(SRC_DIR)/ft_error.c

OBJ = $(SRC_DIR)/ft_main.o\
	  $(SRC_DIR)/ft_map_validation.o\
	  $(SRC_DIR)/ft_map_checker.o\
	  $(SRC_DIR)/ft_set_game.o\
	  $(SRC_DIR)/ft_load_texture.o\
	  $(SRC_DIR)/ft_init_game.o\
	  $(SRC_DIR)/ft_draw_screen.o\
	  $(SRC_DIR)/ft_draw_sprite.o\
	  $(SRC_DIR)/ft_draw_exit.o\
	  $(SRC_DIR)/ft_draw_player.o\
	  $(SRC_DIR)/ft_draw_enemy.o\
	  $(SRC_DIR)/ft_game_status.o\
	  $(SRC_DIR)/ft_move.o\
	  $(SRC_DIR)/ft_string.o\
	  $(SRC_DIR)/ft_enemy.o\
	  $(SRC_DIR)/ft_move_enemy.o\
	  $(SRC_DIR)/mlibft.o\
	  $(SRC_DIR)/ft_free.o\
	  $(SRC_DIR)/ft_error.o

SRC_B = $(SRC__B_DIR)/ft_main.c\
	  $(SRC__B_DIR)/ft_map_validation.c\
	  $(SRC__B_DIR)/ft_map_checker.c\
	  $(SRC__B_DIR)/ft_set_game.c\
	  $(SRC__B_DIR)/ft_load_texture.c\
	  $(SRC__B_DIR)/ft_init_game.c\
	  $(SRC__B_DIR)/ft_draw_screen.c\
	  $(SRC__B_DIR)/ft_draw_sprite.c\
	  $(SRC__B_DIR)/ft_draw_exit.c\
	  $(SRC__B_DIR)/ft_draw_player.c\
	  $(SRC__B_DIR)/ft_draw_enemy.c\
	  $(SRC__B_DIR)/ft_game_status.c\
	  $(SRC__B_DIR)/ft_move.c\
	  $(SRC__B_DIR)/ft_string.c\
	  $(SRC__B_DIR)/ft_enemy.c\
	  $(SRC__B_DIR)/ft_move_enemy.c\
	  $(SRC__B_DIR)/mlibft.c\
	  $(SRC__B_DIR)/ft_free.c\
	  $(SRC__B_DIR)/ft_error.c

OBJ_B = $(SRC__B_DIR)/ft_main.o\
	  $(SRC__B_DIR)/ft_map_validation.o\
	  $(SRC__B_DIR)/ft_map_checker.o\
	  $(SRC__B_DIR)/ft_set_game.o\
	  $(SRC__B_DIR)/ft_load_texture.o\
	  $(SRC__B_DIR)/ft_init_game.o\
	  $(SRC__B_DIR)/ft_draw_screen.o\
	  $(SRC__B_DIR)/ft_draw_sprite.o\
	  $(SRC__B_DIR)/ft_draw_exit.o\
	  $(SRC__B_DIR)/ft_draw_player.o\
	  $(SRC__B_DIR)/ft_draw_enemy.o\
	  $(SRC__B_DIR)/ft_game_status.o\
	  $(SRC__B_DIR)/ft_move.o\
	  $(SRC__B_DIR)/ft_string.o\
	  $(SRC__B_DIR)/ft_enemy.o\
	  $(SRC__B_DIR)/ft_move_enemy.o\
	  $(SRC__B_DIR)/mlibft.o\
	  $(SRC__B_DIR)/ft_free.o\
	  $(SRC__B_DIR)/ft_error.o

all : $(NAME)

$(NAME) : $(OBJ)
	rm -f $(OBJ_B) $(BONUS_HIDE)
	gcc $(CFLAGS) -L./$(INCLUDE) -o $(NAME) $(OBJ)

bonus : $(BONUS_HIDE)

$(BONUS_HIDE) : $(OBJ_B)
	touch $(BONUS_HIDE)
	rm -f $(OBJ)
	gcc $(CFLAGS) -L./$(INCLUDE) -o $(NAME) $(OBJ_B)

clean :
	rm -f $(OBJ) $(OBJ_B) $(BONUS_HIDE)

fclean : clean
	rm -f $(NAME)

re : fclean all
