/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gejo <gejo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/11 23:34:14 by gejo              #+#    #+#             */
/*   Updated: 2021/07/15 20:37:05 by gejo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int ft_file_name(char *map_file)
{
	int i;

	i = 0;
	while (map_file[i] != '\0')
		i++;
	if (map_file[i - 1] == 'r' && map_file[i - 2] == 'e' &&
			map_file[i - 3] == 'b' && map_file[i - 4] == '.')
		return (1);
	return (0);
}

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
					ft_putstr_fd("Error\nlast line check fail\n", 2);
			}
			else
				ft_putstr_fd("Error\nline length check fail\n", 2);
		}
		else
			ft_putstr_fd("Error\nline check fail\n", 2);
	}
	else
		ft_putstr_fd("Error\n1st line check fail\n", 2);
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
		ft_putstr_fd("Error\nmalloc fail\n", 2);
		exit(1);
	}
	if (ft_map_close_check(map) != 1)
	{
		ft_putstr_fd("Error\nmap invalid\n", 2);
		exit(1);
	}
	if (ft_exist_data(map->m_str) != 1)
	{
		ft_putstr_fd("Error\ngame data invalid\n", 2);
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
	{
		ft_putstr_fd("Error\nmalloc fail\n", 2);
		exit(1);
	}
	i = 0;
	idx = 0;
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

void ft_backup_map(t_game *game)
{
	int i;
	int j;
	char *tmp;

	game->map_backup = malloc((game->y + 1) * sizeof(char *));
	if (game->map_backup == NULL)
		exit(1);
	i = 0;
	while (game->map[i] != NULL)
	{
		game->map_backup[i] = ft_strdup(game->map[i]);
		i++;
	}
	game->map_backup[i] = NULL;
}

t_game *ft_set_game(char *m_str)
{
	t_game *game;
	
	game = malloc(sizeof(t_game));
	if (game == NULL)
		return (NULL);
	ft_init_map(game, m_str);
	ft_backup_map(game);
	return (game);
}

// start using mlx
//

void ft_player_animation(t_game *game)
{
	int timer;

	timer = game->player_timer;
	if (game->p_stone == 0)
	{
		if (timer < 5 || timer > 25)
			mlx_put_image_to_window(game->mlx_ptr, game->mlx_win,
				game->tex_player.img, game->p_x * TILE_SIZE, game->p_y * TILE_SIZE);
		else if (timer < 10 || timer > 20)
			mlx_put_image_to_window(game->mlx_ptr, game->mlx_win,
				game->tex_player.img_2, game->p_x * TILE_SIZE, game->p_y * TILE_SIZE);
		else
			mlx_put_image_to_window(game->mlx_ptr, game->mlx_win,
				game->tex_player.img_3, game->p_x * TILE_SIZE, game->p_y * TILE_SIZE);
	}
	else
	{
		if (timer < 5 || timer > 25)
			mlx_put_image_to_window(game->mlx_ptr, game->mlx_win,
				game->tex_player.c_img1, game->p_x * TILE_SIZE, game->p_y * TILE_SIZE);
		else if (timer < 10 || timer > 20)
			mlx_put_image_to_window(game->mlx_ptr, game->mlx_win,
				game->tex_player.c_img2, game->p_x * TILE_SIZE, game->p_y * TILE_SIZE);
		else
			mlx_put_image_to_window(game->mlx_ptr, game->mlx_win,
				game->tex_player.c_img3, game->p_x * TILE_SIZE, game->p_y * TILE_SIZE);
	}
	if (timer > 30)
		game->player_timer = 0;
}

void ft_draw_player(t_game *game)
{
	game->player_timer++;
	ft_player_animation(game);
}

void ft_draw_enemy(t_game *game)
{
	game->enemy_timer++;
	mlx_put_image_to_window(game->mlx_ptr, game->mlx_win,
			game->tex_enemy.img, game->e_x * TILE_SIZE, game->e_y * TILE_SIZE);
}

void ft_exit_animation(t_game *game, int i, int j)
{
	int timer;

	timer = game->sprite_timer;
	if (timer < 5 || timer > 35)
		mlx_put_image_to_window(game->mlx_ptr, game->mlx_win,
				game->tex_exit.c_img1, j, i);
	else if (timer < 10 || timer > 30)
		mlx_put_image_to_window(game->mlx_ptr, game->mlx_win,
				game->tex_exit.c_img2, j, i);
	else if (timer < 15 || timer > 25)
		mlx_put_image_to_window(game->mlx_ptr, game->mlx_win,
				game->tex_exit.c_img3, j, i);
	else
		mlx_put_image_to_window(game->mlx_ptr, game->mlx_win,
				game->tex_exit.c_img4, j, i);
}

void ft_draw_exit(t_game *game)
{
	int i;
	int j;

	i = 0;
	while (game->map[i] != NULL)
	{
		j = 0;
		while (game->map[i][j] != '\0')
		{
			if (game->map[i][j] == 'E')
				ft_exit_animation(game, i * TILE_SIZE, j * TILE_SIZE); // bonus sprite_ani
			j++;
		}
		i++;
	}
}

void ft_sprite_animation(t_game *game, int i, int j)
{
	int timer;

	timer = game->sprite_timer;
	if (timer < 5 || timer > 35)
		mlx_put_image_to_window(game->mlx_ptr, game->mlx_win,
				game->tex_collect.c_img1, j, i);
	else if (timer < 10 || timer > 30)
		mlx_put_image_to_window(game->mlx_ptr, game->mlx_win,
				game->tex_collect.c_img2, j, i);
	else if (timer < 15 || timer > 25)
		mlx_put_image_to_window(game->mlx_ptr, game->mlx_win,
				game->tex_collect.c_img3, j, i);
	else
		mlx_put_image_to_window(game->mlx_ptr, game->mlx_win,
				game->tex_collect.c_img4, j, i);
	if (game->sprite_timer > 40)
		game->sprite_timer = 0;
}

void ft_draw_sprite(t_game *game)
{
	int i;
	int j;

	game->sprite_timer++;
	i = 0;
	while (game->map[i] != NULL)
	{
		j = 0;
		while (game->map[i][j] != '\0')
		{
			if (game->map[i][j] == 'C')
				ft_sprite_animation(game, i * TILE_SIZE, j * TILE_SIZE); // bonus sprite_ani
			j++;
		}
		i++;
	}
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
			else if (game->map[i][j] == 'B')
				mlx_put_image_to_window(game->mlx_ptr, game->mlx_win,
						game->tex_stone.img, j * TILE_SIZE, i * TILE_SIZE);
			else if (game->map[i][j] == 'E')
				mlx_put_image_to_window(game->mlx_ptr, game->mlx_win,
						game->tex_exit.img, j * TILE_SIZE, i * TILE_SIZE);
			else
				mlx_put_image_to_window(game->mlx_ptr, game->mlx_win,
						game->tex_tile.img, j * TILE_SIZE, i * TILE_SIZE);
			j++;
		}
		i++;
	}
}

void ft_touch_collect(t_game *game)
{
	if (game->map[game->p_y][game->p_x] == 'C')
		game->number_of_collections--;
	if (game->map[game->p_y][game->p_x] != 'E')
	{
		if (game->p_stone == 0)
		{
			game->map[game->p_y][game->p_x] = 'B';
			game->p_stone = 1;
		}
		else
		{
			game->map[game->p_y][game->p_x] = '1';
			game->p_stone = 0;
		}
	}
}

void	ft_game_message(t_game *game, int color)
{
	mlx_string_put(game->mlx_ptr, game->mlx_win,
			game->x * TILE_SIZE / 2, game->y * TILE_SIZE / 2 + 10,
			color, "EXIT : ESC");
	mlx_string_put(game->mlx_ptr, game->mlx_win,
			game->x * TILE_SIZE / 2, game->y * TILE_SIZE / 2 + 20,
			color, "REPLAY : R");
}

void ft_game_status(t_game *game)
{
	if (game->exit_status == 1)
	{
		mlx_string_put(game->mlx_ptr, game->mlx_win,
				game->x * TILE_SIZE / 2, game->y * TILE_SIZE / 2,
				0x0000FF, "YOU WIN");
		ft_game_message(game, 0x0000FF);
	}
	else if (game->enemy_status == 1)
	{
		mlx_string_put(game->mlx_ptr, game->mlx_win,
				game->x * TILE_SIZE / 2, game->y * TILE_SIZE / 2,
				0xFF0000, "YOU LOSE");
		ft_game_message(game, 0xFF0000);
	}
	else
	{
		mlx_string_put(game->mlx_ptr, game->mlx_win,
				1, 10, 0x0000FF, game->move_str);
		mlx_string_put(game->mlx_ptr, game->mlx_win,
				1, 20, 0x0000FF, "EXIT : ESC");
		mlx_string_put(game->mlx_ptr, game->mlx_win,
				1, 30, 0x0000FF, "REPLAY : R");
	}
}

int ft_game_loop(t_game *game)
{
	if (game->exit_status == 0 && game->enemy_status == 0)
	{
		ft_draw_screen(game);
		ft_draw_sprite(game);
		ft_draw_exit(game);
		ft_draw_player(game);
//		ft_move_enemy(game);
//		ft_draw_enemy(game);
		ft_game_status(game);
	}
//	ft_enemy_count_manager(game);
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
	game->tex_player.img = mlx_xpm_file_to_image(game->mlx_ptr, "./texture/player1.xpm",
			&(game->tex_player.width), &(game->tex_player.height));
	game->tex_player.data = (int *)mlx_get_data_addr(game->tex_player.img,
			&game->tex_player.bpp, &game->tex_player.size_l, &game->tex_player.endian);
	game->tex_player.img_2 = mlx_xpm_file_to_image(game->mlx_ptr, "./texture/player2.xpm",
			&(game->tex_player.width), &(game->tex_player.height));
	game->tex_player.img_3 = mlx_xpm_file_to_image(game->mlx_ptr, "./texture/player3.xpm",
			&(game->tex_player.width), &(game->tex_player.height));
	game->tex_player.c_img1 = mlx_xpm_file_to_image(game->mlx_ptr, "./texture/w_player1.xpm",
			&(game->tex_player.width), &(game->tex_player.height));
	game->tex_player.c_img2 = mlx_xpm_file_to_image(game->mlx_ptr, "./texture/w_player2.xpm",
			&(game->tex_player.width), &(game->tex_player.height));
	game->tex_player.c_img3 = mlx_xpm_file_to_image(game->mlx_ptr, "./texture/w_player3.xpm",
			&(game->tex_player.width), &(game->tex_player.height));
}

void ft_collect_texture(t_game *game)
{
	game->tex_collect.c_img1 = mlx_xpm_file_to_image(game->mlx_ptr, "./texture/gold_01.xpm",
			&(game->tex_collect.width), &(game->tex_collect.height));
	game->tex_collect.data = (int *)mlx_get_data_addr(game->tex_collect.c_img1,
			&game->tex_collect.bpp, &game->tex_collect.size_l, &game->tex_collect.endian);
	game->tex_collect.c_img2 = mlx_xpm_file_to_image(game->mlx_ptr, "./texture/gold_02.xpm",
			&(game->tex_collect.width), &(game->tex_collect.height));
	game->tex_collect.c_img3 = mlx_xpm_file_to_image(game->mlx_ptr, "./texture/gold_03.xpm",
			&(game->tex_collect.width), &(game->tex_collect.height));
	game->tex_collect.c_img4 = mlx_xpm_file_to_image(game->mlx_ptr, "./texture/gold_04.xpm",
			&(game->tex_collect.width), &(game->tex_collect.height));
}

void ft_exit_texture(t_game *game)
{
	game->tex_exit.c_img1 = mlx_xpm_file_to_image(game->mlx_ptr, "./texture/sprite1.xpm",
			&(game->tex_exit.width), &(game->tex_exit.height));
	game->tex_exit.data = (int *)mlx_get_data_addr(game->tex_exit.c_img1,
			&game->tex_exit.bpp, &game->tex_exit.size_l, &game->tex_exit.endian);
	game->tex_exit.c_img2 = mlx_xpm_file_to_image(game->mlx_ptr, "./texture/sprite2.xpm",
			&(game->tex_exit.width), &(game->tex_exit.height));
	game->tex_exit.c_img3 = mlx_xpm_file_to_image(game->mlx_ptr, "./texture/sprite3.xpm",
			&(game->tex_exit.width), &(game->tex_exit.height));
	game->tex_exit.c_img4 = mlx_xpm_file_to_image(game->mlx_ptr, "./texture/sprite4.xpm",
			&(game->tex_exit.width), &(game->tex_exit.height));
}

void ft_load_texture(t_game *game)
{
	// wall : white stone
	game->tex_wall.img = mlx_xpm_file_to_image(game->mlx_ptr, "./texture/wall.xpm",
			&(game->tex_wall.width), &(game->tex_wall.height));
	game->tex_wall.data = (int *)mlx_get_data_addr(game->tex_wall.img,
			&game->tex_wall.bpp, &game->tex_wall.size_l, &game->tex_wall.endian);
//	ft_save_texture(game, game->tex_wall);
//	tile : go
	game->tex_tile.img = mlx_xpm_file_to_image(game->mlx_ptr, "./texture/tile.xpm",
			&(game->tex_tile.width), &(game->tex_tile.height));
	game->tex_tile.data = (int *)mlx_get_data_addr(game->tex_tile.img,
			&game->tex_tile.bpp, &game->tex_tile.size_l, &game->tex_tile.endian);
	// collect : gray stone which place a black stone
	game->tex_collect.img = mlx_xpm_file_to_image(game->mlx_ptr, "./texture/collect.xpm",
			&(game->tex_collect.width), &(game->tex_collect.height));
	game->tex_collect.data = (int *)mlx_get_data_addr(game->tex_collect.img,
			&game->tex_collect.bpp, &game->tex_collect.size_l, &game->tex_collect.endian);
	// b_stone : black_stone, key_space active
	game->tex_stone.img = mlx_xpm_file_to_image(game->mlx_ptr, "./texture/b_stone.xpm",
			&(game->tex_stone.width), &(game->tex_stone.height));
	game->tex_stone.data = (int *)mlx_get_data_addr(game->tex_stone.img,
			&game->tex_stone.bpp, &game->tex_stone.size_l, &game->tex_stone.endian);
	// exit : gold stone, collections == 0 active
	game->tex_exit.img = mlx_xpm_file_to_image(game->mlx_ptr, "./texture/gold_stone.xpm",
			&(game->tex_exit.width), &(game->tex_exit.height));
	game->tex_exit.data = (int *)mlx_get_data_addr(game->tex_exit.img,
			&game->tex_exit.bpp, &game->tex_exit.size_l, &game->tex_exit.endian);

	ft_collect_texture(game);
	ft_player_texture(game);
	ft_exit_texture(game);
}

void ft_init_player_position(t_game *game)
{
	int i;
	int j;

	i = 0;
	while (game->map[i] != NULL)
	{
		j = 0;
		while (game->map[i][j] != '\0')
		{
			if (game->map[i][j] == 'P')
			{
				game->p_x = j;
				game->p_y = i;
				break ;
			}
			j++;
		}
		i++;
	}
	game->move_count = 0;
	game->player_timer = 0;
}

void ft_init_collections(t_game *game)
{
	int i;
	int j;
	int count;

	count = 0;
	i = 0;
	while (game->map[i] != NULL)
	{
		j = 0;
		while (game->map[i][j] != '\0')
		{
			if (game->map[i][j] == 'C')
				count++;
			j++;
		}
		i++;
	}
	game->sprite_timer = 0;
	game->number_of_collections = count;
}

void ft_init_game(t_game *game)
{
	game->mlx_ptr = mlx_init();
	game->mlx_win = mlx_new_window(game->mlx_ptr, TILE_SIZE * game->x, TILE_SIZE * game->y, "SO_LONG");
	ft_load_texture(game);
	ft_init_player_position(game);
	ft_init_collections(game);
	game->exit_status = 0;
	game->p_stone = 0;
	game->move_str = NULL;
	ft_str_move_count(game);
	ft_enemy_texture(game);
	ft_init_enemy(game);
}

void ft_start_game(t_game *game)
{
	ft_init_game(game);
	mlx_hook(game->mlx_win, EVENT_KEY_RELEASE, 0, key_press, game);
	mlx_hook(game->mlx_win, EVENT_KEY_DESTROY_NOTIFY, 0, ft_game_close, game);
	mlx_loop_hook(game->mlx_ptr, &ft_game_loop, game);
	mlx_loop(game->mlx_ptr);
}

void ft_game(char *map_file)
{
	t_map *map;
	t_game *game;
	if (ft_file_name(map_file) != 1)
	{
		ft_putstr_fd("Error\nfile name must end .ber\n", 2);
		exit(1);
	}
	map = ft_map_validation(map_file);
	if (map == NULL)
	{
		ft_putstr_fd("Error\nmalloc fail\n", 2);
		exit(1);
	}
	game = ft_set_game(map->m_str);
	if (game == NULL)
		exit(1);
	free(map->m_str);
	free(map);
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
