/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_enemy_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gejo <gejo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/16 12:00:32 by gejo              #+#    #+#             */
/*   Updated: 2021/07/17 17:02:13 by gejo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_bonus.h"

void	ft_enemy_count_manager(t_game *game)
{
	game->enemy_count++;
	if (game->enemy_count > game->x * game->y)
		game->enemy_count = 0;
}

void	ft_enemy_texture(t_game *game)
{
	game->tex_enemy.img = mlx_xpm_file_to_image(
			game->mlx_ptr, "./texture/alphago.xpm",
			&game->tex_enemy.width, &game->tex_enemy.height);
}

void	ft_init_enemy(t_game *game)
{
	game->enemy_count = 0;
	game->enemy_status = 0;
	game->enemy_timer = 0;
	game->e_x = 0;
	game->e_y = 0;
	ft_enemy_random_position(game);
}

void	ft_set_enemy_position(t_game *game, int e_x, int e_y)
{
	while (game->map[e_y][e_x] == '1' || game->map[e_y][e_x] == 'P')
	{
		if (e_x == 0)
			e_x++;
		else if (e_x == game->x - 1)
			e_x--;
		else if (e_y == 0)
			e_y++;
		else if (e_y == game->y - 1)
			e_y--;
		else
		{
			if (e_x > (game->x / 2) && e_x < (game->x - 1))
				e_x--;
			else
				e_x++;
			if (e_y > (game->y / 2) && e_y > (game->y - 1))
				e_y--;
			else
				e_y++;
		}
	}
	game->e_x = e_x;
	game->e_y = e_y;
}

void	ft_enemy_random_position(t_game *game)
{
	int		enemy_x;
	int		enemy_y;

	enemy_x = 0;
	enemy_y = 0;
	if (game->e_x == 0 && game->e_y == 0)
	{
		enemy_x = enemy_x + game->map[game->y / 4][game->x / 2] % game->x;
		enemy_y = enemy_y + game->map[game->y / 2][game->x / 4] % game->y;
	}
	else
	{
		enemy_x = (enemy_x + game->e_y + game->enemy_count * 4) % game->x;
		enemy_y = (enemy_y + game->e_x + game->enemy_count * 2) % game->y;
	}
	if (enemy_x < 0)
		enemy_x = enemy_x * -1;
	if (enemy_y < 0)
		enemy_y = enemy_y * -1;
	ft_set_enemy_position(game, enemy_x, enemy_y);
}
