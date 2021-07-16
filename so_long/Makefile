# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gejo <gejo@student.42seoul.kr>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/10 22:25:57 by gejo              #+#    #+#              #
#    Updated: 2021/07/16 20:32:48 by gejo             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

CFLAGS = -g3 -fsanitize=address -L./mlx -lmlx -framework OpenGL -framework Appkit

INCLUDE = include

SRC_DIR = srcs

SRC_B_DIR = srcs_b

BONUS_HIDE = .bonus

SRC	= $(SRC_DIR)/ft_main.c\
	  $(SRC_DIR)/ft_map_validation.c\
	  $(SRC_DIR)/ft_open_read_file.c\
	  $(SRC_DIR)/ft_map_checker.c\
	  $(SRC_DIR)/ft_set_game.c\
	  $(SRC_DIR)/ft_load_texture.c\
	  $(SRC_DIR)/ft_init_game.c\
	  $(SRC_DIR)/ft_draw_screen.c\
	  $(SRC_DIR)/ft_draw_sprite.c\
	  $(SRC_DIR)/ft_draw_exit.c\
	  $(SRC_DIR)/ft_draw_player.c\
	  $(SRC_DIR)/ft_game_status.c\
	  $(SRC_DIR)/ft_move.c\
	  $(SRC_DIR)/ft_string.c\
	  $(SRC_DIR)/mlibft.c\
	  $(SRC_DIR)/ft_free.c\
	  $(SRC_DIR)/ft_error.c

OBJ = $(SRC_DIR)/ft_main.o\
	  $(SRC_DIR)/ft_map_validation.o\
	  $(SRC_DIR)/ft_open_read_file.o\
	  $(SRC_DIR)/ft_map_checker.o\
	  $(SRC_DIR)/ft_set_game.o\
	  $(SRC_DIR)/ft_load_texture.o\
	  $(SRC_DIR)/ft_init_game.o\
	  $(SRC_DIR)/ft_draw_screen.o\
	  $(SRC_DIR)/ft_draw_sprite.o\
	  $(SRC_DIR)/ft_draw_exit.o\
	  $(SRC_DIR)/ft_draw_player.o\
	  $(SRC_DIR)/ft_game_status.o\
	  $(SRC_DIR)/ft_move.o\
	  $(SRC_DIR)/ft_string.o\
	  $(SRC_DIR)/mlibft.o\
	  $(SRC_DIR)/ft_free.o\
	  $(SRC_DIR)/ft_error.o

SRC_B = $(SRC_B_DIR)/ft_main_bonus.c\
	  $(SRC_B_DIR)/ft_map_validation_bonus.c\
	  $(SRC_B_DIR)/ft_open_read_file_bonus.c\
	  $(SRC_B_DIR)/ft_map_checker_bonus.c\
	  $(SRC_B_DIR)/ft_set_game_bonus.c\
	  $(SRC_B_DIR)/ft_load_texture_bonus.c\
	  $(SRC_B_DIR)/ft_init_game_bonus.c\
	  $(SRC_B_DIR)/ft_draw_screen_bonus.c\
	  $(SRC_B_DIR)/ft_draw_sprite_bonus.c\
	  $(SRC_B_DIR)/ft_draw_exit_bonus.c\
	  $(SRC_B_DIR)/ft_draw_player_bonus.c\
	  $(SRC_B_DIR)/ft_draw_enemy_bonus.c\
	  $(SRC_B_DIR)/ft_game_status_bonus.c\
	  $(SRC_B_DIR)/ft_move_bonus.c\
	  $(SRC_B_DIR)/ft_string_bonus.c\
	  $(SRC_B_DIR)/ft_enemy_bonus.c\
	  $(SRC_B_DIR)/ft_move_enemy_bonus.c\
	  $(SRC_B_DIR)/mlibft_bonus.c\
	  $(SRC_B_DIR)/ft_free_bonus.c\
	  $(SRC_B_DIR)/ft_error_bonus.c

OBJ_B = $(SRC_B_DIR)/ft_main_bonus.o\
	  $(SRC_B_DIR)/ft_map_validation_bonus.o\
	  $(SRC_B_DIR)/ft_open_read_file_bonus.o\
	  $(SRC_B_DIR)/ft_map_checker_bonus.o\
	  $(SRC_B_DIR)/ft_set_game_bonus.o\
	  $(SRC_B_DIR)/ft_load_texture_bonus.o\
	  $(SRC_B_DIR)/ft_init_game_bonus.o\
	  $(SRC_B_DIR)/ft_draw_screen_bonus.o\
	  $(SRC_B_DIR)/ft_draw_sprite_bonus.o\
	  $(SRC_B_DIR)/ft_draw_exit_bonus.o\
	  $(SRC_B_DIR)/ft_draw_player_bonus.o\
	  $(SRC_B_DIR)/ft_draw_enemy_bonus.o\
	  $(SRC_B_DIR)/ft_game_status_bonus.o\
	  $(SRC_B_DIR)/ft_move_bonus.o\
	  $(SRC_B_DIR)/ft_string_bonus.o\
	  $(SRC_B_DIR)/ft_enemy_bonus.o\
	  $(SRC_B_DIR)/ft_move_enemy_bonus.o\
	  $(SRC_B_DIR)/mlibft_bonus.o\
	  $(SRC_B_DIR)/ft_free_bonus.o\
	  $(SRC_B_DIR)/ft_error_bonus.o

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
