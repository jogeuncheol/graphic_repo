/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gejo <gejo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/11 23:34:14 by gejo              #+#    #+#             */
/*   Updated: 2021/07/12 23:24:19 by gejo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char *ft_map_str(char *map_file)
{
	int fd;
	char *tmp;
	char *m_str;
	char buff[2];
	
	m_str = NULL;
	tmp = NULL;
	fd = open(map_file, O_RDONLY);
	while (read(fd, buff, 1) > 0)
	{
		buff[1] = '\0';
		tmp = ft_strjoin(m_str, buff);
		free(m_str);
		m_str = NULL;
		m_str = tmp;
	}
	printf("%s", m_str);	// m_str print
	return (m_str);
}

int ft_check_1st_line(char *m_str)
{
	int i;

	i = 0;
	while (m_str[i] != '\n')
	{
		if (m_str[i] == '1')
			i++;
		else
			return (0);
	}
	return (1);
}

int ft_check_map_char(char c)
{
	if (c == '0' || c== '1')
		return (1);
	else if (c == 'C' || c == 'P' || c == 'E')
		return (1);
	else
		return (0);
}

int ft_check_line(char *m_str)
{
	int i;
	int valid_line;

	i = 0;
	while (m_str[i] != '\0')
	{
		valid_line = 0;
		if (m_str[i] == '\n' && m_str[i + 1] != '\0')
		{
			if (m_str[i - 1] == '1' && m_str[i + 1] == '1')
				valid_line = 1;
			if (valid_line != 1)
				return (0);
		}
		else if (m_str[i] != '\n' && ft_check_map_char(m_str[i]) == 0)
			return (0);
		i++;
	}
	return (1);
}

int ft_check_length_line(char *m_str)
{
	int i;
	int j;
	int len;

	i = 0;
	while (m_str[i] != '\n')
		i++;
	len = i++;
	while (m_str[i] != '\0')
	{
		j = 0;
		while (m_str[i] != '\n' && m_str[i] != '\0')
		{
			i++;
			j++;
		}
		if (j != len)
			return (0);
		if (m_str[i] == '\0')
			break ;
		i++;
	}
	return (1);
}

int ft_check_last_line(char *m_str)
{
	int i;

	i = 0;
	while (m_str[i + 1] != '\0')
		i++;
	if (m_str[i] == '\n')
		i--;
	while (m_str[i] != '\n')
	{
		if (m_str[i] == '1')
			i--;
		else
			return (0);
	}
	return (1);
}

int ft_map_close_check(t_map *map)
{
	if (ft_check_1st_line(map->m_str) == 1)
	{
		if (ft_check_line(map->m_str) == 1)
		{
			if (ft_check_length_line(map->m_str) == 1)
			{
				if (ft_check_last_line(map->m_str) == 1)
					return (1);
				else
					printf("last line check fail\n");
			}
			else
				printf("line length check fail\n");
		}
		else
			printf("line check fail\n");
	}
	else
		printf("1st line check fail\n");
	return (0);
}

int ft_exist_data(char *m_str)
{
	int c;
	int e;
	int p;
	int i;
	
	c = 0;
	e = 0;
	p = 0;
	i = 0;
	while (m_str[i] != '\0')
	{
		if (m_str[i] == 'C')
			c++;
		else if (m_str[i] == 'E')
			e++;
		else if (m_str[i] == 'P')
			p++;
		i++;
	}
	if (p != 1)
		return (0);
	else if (c < 1 || e < 1)
		return (0);
	return (1);
}

t_map *ft_map_validation(char *map_file)
{
	t_map *map;

	map = malloc(sizeof(t_map));
	if (map == NULL)
		return (NULL);
	map->m_str = ft_map_str(map_file);
	if (map->m_str == NULL)
	{
		printf("malloc fail\n");
		exit(1);
	}
	if (ft_map_close_check(map) == 1)
		printf("map valid check pass\n");
	else
	{
		printf("map invalid\n");
		exit(1);
	}
	if (ft_exist_data(map->m_str) == 1)
		printf("game data valid check pass\n");
	else
	{
		printf("game data invalid\n");
		exit(1);
	}
	return (map);
}

void ft_init_map_xy(t_game *game, char *m_str)
{
	int i;
	int line;

	i = 0;
	while (m_str[i] != '\n')
		i++;
	game->x = i;
	line = 1;
	while (m_str[i + 1] != '\0')
	{
		if (m_str[i] == '\n')
			line++;
		i++;
	}
	game->y = line;
}

void ft_init_map(t_game *game, char *m_str)
{
	int		i;
	int		idx;
	char	*tmp;

	ft_init_map_xy(game, m_str);
	game->map = malloc((game->y + 1) * sizeof(char *));
	if (game->map == NULL)
		exit(1);
	i = 0;
	tmp = &m_str[i];
	while (m_str[i] != '\0')
	{
		if (m_str[i] == '\n')
		{
			m_str[i] = '\0';
			game->map[idx] = ft_strdup(tmp);
			idx++;
			tmp = &m_str[i + 1];
		}
		i++;
	}
	game->map[idx] = NULL;
}

t_game *ft_set_game(char *m_str)
{
	t_game *game;
	
	game = malloc(sizeof(t_game));
	if (game == NULL)
		return (NULL);
	ft_init_map(game, m_str);
	return (game);
}

// start using mlx
//

void ft_draw_player(t_game *game)
{
}

void ft_draw_screen(t_game *game)
{
	int i;
	int j;

	i = 0;
	while (game->map[i] != NULL)
	{
		j = 0;
		while (game->map[i][j] != '\0')
		{
			if (game->map[i][j] == '1')
				mlx_put_image_to_window(game->mlx_ptr, game->mlx_win,
						game->tex_wall.img, j * TILE_SIZE, i * TILE_SIZE);
			else if (game->map[i][j] == '0')
				mlx_put_image_to_window(game->mlx_ptr, game->mlx_win,
						game->tex_tile.img, j * TILE_SIZE, i * TILE_SIZE);
			else if (game->map[i][j] == 'P')
				mlx_put_image_to_window(game->mlx_ptr, game->mlx_win,
						game->tex_player.img, j * TILE_SIZE, i * TILE_SIZE);
			j++;
		}
		i++;
	}
}

int ft_game_loop(t_game *game)
{
	ft_draw_screen(game);
	return (0);
}

void ft_save_texture(t_game *game, t_img img)
{
	int x;
	int y;

	y = 0;
	while (y < TILE_SIZE)
	{
		x = 0;
		while (x < TILE_SIZE)
		{
			game->texture_wall[y][x] = img.data[(y * TILE_SIZE) + x];
			x++;
		}
		y++;
	}
}

void ft_player_texture(t_game *game)
{
	game->tex_player.img = mlx_xpm_file_to_image(game->mlx_ptr, "./texture/p_s.xpm",
			&(game->tex_player.width), &(game->tex_player.height));
	game->tex_player.data = (int *)mlx_get_data_addr(game->tex_player.img,
			&game->tex_player.bpp, &game->tex_player.size_l, &game->tex_player.endian);
}

void ft_load_texture(t_game *game)
{
	game->tex_wall.img = mlx_xpm_file_to_image(game->mlx_ptr, "./texture/wall.xpm",
			&(game->tex_wall.width), &(game->tex_wall.height));
	game->tex_wall.data = (int *)mlx_get_data_addr(game->tex_wall.img,
			&game->tex_wall.bpp, &game->tex_wall.size_l, &game->tex_wall.endian);
//	ft_save_texture(game, game->tex_wall);
	game->tex_tile.img = mlx_xpm_file_to_image(game->mlx_ptr, "./texture/tile.xpm",
			&(game->tex_tile.width), &(game->tex_tile.height));
	game->tex_tile.data = (int *)mlx_get_data_addr(game->tex_tile.img,
			&game->tex_tile.bpp, &game->tex_tile.size_l, &game->tex_tile.endian);
//	ft_save_texture(game, game->tex_tile);
	ft_player_texture(game);
}

void ft_init_game(t_game *game)
{
	game->mlx_ptr = mlx_init();
	game->mlx_win = mlx_new_window(game->mlx_ptr, TILE_SIZE * game->x, TILE_SIZE * game->y, "SO_LONG");
	ft_load_texture(game);
//	ft_player_position(game);
}

void ft_start_game(t_game *game)
{
	ft_init_game(game);
	mlx_loop_hook(game->mlx_ptr, &ft_game_loop, game);
	mlx_loop(game->mlx_ptr);
}

void ft_game(char *map_file)
{
	t_map *map;
	t_game *game;
	map = ft_map_validation(map_file);
	if (map == NULL)
	{
		printf("malloc fail\n");
		exit(1);
	}
	game = ft_set_game(map->m_str);
	if (game == NULL)
		exit(1);
	ft_start_game(game);
}

int main(int argc, char *argv[])
{
	if (argc == 2)
		ft_game(argv[1]);
	else
	{
		printf("Error\n");
		exit(1);
	}
	return (0);
}
