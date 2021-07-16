/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_game.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gejo <gejo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/16 13:25:10 by gejo              #+#    #+#             */
/*   Updated: 2021/07/16 17:00:06 by gejo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_init_player_position(t_game *game)
{
	int		i;
	int		j;

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

void	ft_init_collections(t_game *game)
{
	int		i;
	int		j;
	int		count;

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

void	ft_init_game(t_game *game)
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
