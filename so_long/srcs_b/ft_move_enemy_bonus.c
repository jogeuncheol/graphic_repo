/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_enemy_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gejo <gejo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/14 19:44:14 by gejo              #+#    #+#             */
/*   Updated: 2021/07/16 22:04:05 by gejo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_bonus.h"

void	ft_enemy_collision(t_game *game)
{
	if ((game->p_x == game->e_x) && (game->p_y == game->e_y))
		game->enemy_status = 1;
}

void	ft_e_move_x(t_game *game, int e_x, int e_y)
{
	if (game->p_x < e_x && game->map[e_y][e_x - 1] != '1'
		&& game->map[e_y][e_x - 1] != 'B')
		game->e_x--;
	else if (game->map[e_y][e_x + 1] != '1' && game->map[e_y][e_x + 1] != 'B')
		game->e_x++;
	else if (game->p_y < e_y && game->map[e_y - 1][e_x] != '1'
		&& game->map[e_y - 1][e_x] != 'B')
		game->e_y--;
	else if (game->map[e_y + 1][e_x] != '1' && game->map[e_y + 1][e_x] != 'B')
		game->e_y++;
}

void	ft_e_move_y(t_game *game, int e_x, int e_y)
{
	if (game->p_y < e_y && game->map[e_y - 1][e_x] != '1'
		&& game->map[e_y - 1][e_x] != 'B')
		game->e_y--;
	else if (game->map[e_y + 1][e_x] != '1' && game->map[e_y + 1][e_x] != 'B')
		game->e_y++;
	else if (game->p_x < e_x && game->map[e_y][e_x - 1] != '1'
		&& game->map[e_y][e_x - 1] != 'B')
		game->e_x--;
	else if (game->map[e_y][e_x + 1] != '1' && game->map[e_y][e_x + 1] != 'B')
		game->e_x++;
}

void	ft_enemy_ai(t_game *game)
{
	int		flow_x;
	int		flow_y;

	flow_x = game->e_x - game->p_x;
	flow_y = game->e_y - game->p_y;
	if (flow_x < 0)
		flow_x = flow_x * -1;
	if (flow_y < 0)
		flow_y = flow_y * -1;
	if (flow_x > flow_y)
		ft_e_move_x(game, game->e_x, game->e_y);
	else
		ft_e_move_y(game, game->e_x, game->e_y);
}

void	ft_move_enemy(t_game *game)
{
	if (game->enemy_timer > 30)
	{
		game->e_px = game->e_x;
		game->e_py = game->e_y;
		ft_enemy_ai(game);
		game->enemy_timer = 0;
	}
	ft_enemy_collision(game);
}
