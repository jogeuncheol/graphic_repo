/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_game_status.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gejo <gejo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/16 13:54:36 by gejo              #+#    #+#             */
/*   Updated: 2021/07/16 17:00:04 by gejo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_touch_collect(t_game *game)
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

void	ft_game_status(t_game *game)
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
