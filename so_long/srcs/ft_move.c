/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gejo <gejo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/16 12:00:56 by gejo              #+#    #+#             */
/*   Updated: 2021/07/16 17:11:00 by gejo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	ft_game_end(t_game *game)
{
	if (game->number_of_collections == 0)
	{
		game->exit_status = 1;
		ft_game_status(game);
	}
}

int	ft_game_close(t_game *game)
{
	ft_free_map(game->map);
	ft_free_map(game->map_backup);
	free(game->move_str);
	game->move_str = NULL;
	ft_destroy_mlx(game);
	exit(0);
}

void	ft_move(t_game *game, int move_x, int move_y)
{
	int		x;
	int		y;

	x = game->p_x + move_x;
	y = game->p_y + move_y;
	if (game->map[y][x] != '1' && game->map[y][x] != 'B')
	{
		game->p_x = x;
		game->p_y = y;
		game->move_count++;
		ft_str_move_count(game);
		ft_putstr_fd(game->move_str, 1);
		ft_putstr_fd("\n", 1);
	}
}

void	ft_game_reset(t_game *game)
{
	int		i;
	int		j;

	i = 0;
	while (game->map[i] != NULL)
	{
		j = 0;
		while (game->map[i][j] != '\0')
		{
			game->map[i][j] = game->map_backup[i][j];
			j++;
		}
		i++;
	}
	ft_init_player_position(game);
	ft_init_collections(game);
	game->exit_status = 0;
	game->enemy_status = 0;
	game->p_stone = 0;
	ft_str_move_count(game);
	ft_enemy_random_position(game);
}

int	key_press(int key_code, t_game *game)
{
	if (game->exit_status == 0 && game->enemy_status == 0)
	{
		if (key_code == KEY_W)
			ft_move(game, 0, -1);
		else if (key_code == KEY_A)
			ft_move(game, -1, 0);
		else if (key_code == KEY_S)
			ft_move(game, 0, 1);
		else if (key_code == KEY_D)
			ft_move(game, 1, 0);
		else if (key_code == KEY_SPACE)
		{
			ft_touch_collect(game);
			if (game->map[game->p_y][game->p_x] == 'E')
				ft_game_end(game);
		}
	}
	if (key_code == KEY_R)
		ft_game_reset(game);
	else if (key_code == KEY_ESC)
		ft_game_close(game);
	else
		return (0);
	return (0);
}
