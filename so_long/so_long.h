/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gejo <gejo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/16 12:01:53 by gejo              #+#    #+#             */
/*   Updated: 2021/07/16 13:03:51 by gejo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG
# define SO_LONG

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include "../mlx/mlx.h"

# define TILE_SIZE					32
# define KEY_W						13
# define KEY_A						0
# define KEY_S						1
# define KEY_D						2
# define KEY_R						15
# define KEY_SPACE					49
# define KEY_ESC					53

# define EVENT_KEY_RELEASE			3
# define EVENT_KEY_DESTROY_NOTIFY	17

typedef struct s_map
{
	char	*m_str;
	int		p;
	int		e;
	int		c;
	
}			t_map;

typedef struct s_img
{
	void	*img; // init s
	void	*img_2;
	void	*img_3;
	void	*img_4;
	void	*c_img1;
	void	*c_img2;
	void	*c_img3;
	void	*c_img4;
	int		*data;
	int		size_l;
	int		bpp;
	int		endian;
	int		width;
	int		height;
}			t_img;

typedef struct s_game
{
	int		x;
	int		y;
	char	**map;
	char	**map_backup;

	int		p_x;
	int		p_y;
	int		p_stone;
	int		move_count;
	int		e_x;
	int		e_y;
	int		e_px;
	int		e_py;
	int		enemy_count;
	int		enemy_status;
	int		enemy_timer;
	char	*move_str;
	void	*mlx_ptr;
	void	*mlx_win;

	t_img	tex_wall;
	t_img	tex_tile;
	t_img	tex_player;
	t_img	tex_collect;
	t_img	tex_stone;
	t_img	tex_enemy;
	t_img	tex_exit;
	int		bg;
	int		texture_wall[TILE_SIZE][TILE_SIZE];
	int		texture_tile[TILE_SIZE][TILE_SIZE];
	int		texture_player[TILE_SIZE][TILE_SIZE];
	int		texture_collect[TILE_SIZE][TILE_SIZE];
	int		texture_exit[TILE_SIZE][TILE_SIZE];

	int		number_of_collections;
	int		sprite_timer;
	int		player_timer;
	int		exit_status;
}			t_game;

int		ft_strlen(char *str);
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *str, int fd);
char	*ft_strdup(char *str);
char	*ft_strjoin(char *s1, char *s2);

int		key_press(int key_code, t_game *game);
void	ft_touch_collect(t_game *game);
void	ft_init_player_position(t_game * game);
void	ft_init_collections(t_game *game);
void	ft_str_move_count(t_game *game);
void	ft_game_status(t_game *game);
int		ft_game_close(t_game *game);

void	ft_enemy_texture(t_game *game);
void	ft_init_enemy(t_game *game);
void	ft_enemy_random_position(t_game *game);
void	ft_enemy_count_manager(t_game *game);
void	ft_move_enemy(t_game *game);

void	ft_free_map(char **map);
void	ft_destroy_mlx(t_game *game);

#endif
