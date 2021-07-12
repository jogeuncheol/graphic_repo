#ifndef SO_LONG
# define SO_LONG

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include "../mlx/mlx.h"

# define TILE_SIZE 32

typedef struct s_map
{
	char *m_str;
}	t_map;

typedef struct s_img
{
	void	*img; // init s
	void	*img_n;
	void	*img_e;
	void	*img_w;
	int		*data;
	int		size_l;
	int		bpp;
	int		endian;
	int		width;
	int		height;
}	t_img;

typedef struct s_game
{
	int		x;
	int		y;
	char	**map;

	int		p_x;
	int		p_y;
	void	*mlx_ptr;
	void	*mlx_win;

	t_img	tex_wall;
	t_img	tex_tile;
	t_img	tex_player;
	t_img	tex_collect;
	t_img	tex_exit;
	int		texture_wall[TILE_SIZE][TILE_SIZE];
	int		texture_tile[TILE_SIZE][TILE_SIZE];
	int		texture_player[TILE_SIZE][TILE_SIZE];
	int		texture_collect[TILE_SIZE][TILE_SIZE];
	int		texture_exit[TILE_SIZE][TILE_SIZE];
}	t_game;

int ft_strlen(char *str);
char *ft_strdup(char *str);
char *ft_strjoin(char *s1, char *s2);

#endif
