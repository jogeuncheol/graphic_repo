/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_enemy.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gejo <gejo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/14 19:44:14 by gejo              #+#    #+#             */
/*   Updated: 2021/07/14 23:30:10 by gejo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_enemy_collision(t_game *game)
{
	if ((game->p_x == game->e_x) && (game->p_y == game->e_y))
		game->enemy_status = 1;
}

void	ft_e_move_y(t_game *game);
void	ft_e_move_x(t_game *game)
{
	if (game->p_x < game->e_x && game->map[game->e_y][game->e_x - 1] != '1'
			&& game->map[game->e_y][game->e_x - 1] != 'B')
		game->e_x--;
	else if (game->map[game->e_y][game->e_x + 1] != '1'
			&& game->map[game->e_y][game->e_x + 1] != 'B')
		game->e_x++;
	else if (game->p_y < game->e_y && game->map[game->e_y - 1][game->e_x] != '1'
			&& game->map[game->e_y - 1][game->e_x] != 'B')
		game->e_y--;
	else if (game->map[game->e_y + 1][game->e_x] != '1'
			&& game->map[game->e_y + 1][game->e_x] != 'B')
		game->e_y++;

}

void	ft_e_move_y(t_game *game)
{
	if (game->p_y < game->e_y && game->map[game->e_y - 1][game->e_x] != '1'
			&& game->map[game->e_y - 1][game->e_x] != 'B')
		game->e_y--;
	else if (game->map[game->e_y + 1][game->e_x] != '1'
			&& game->map[game->e_y + 1][game->e_x] != 'B')
		game->e_y++;
	else if (game->p_x < game->e_x && game->map[game->e_y][game->e_x - 1] != '1'
			&& game->map[game->e_y][game->e_x - 1] != 'B')
		game->e_x--;
	else if (game->map[game->e_y][game->e_x + 1] != '1'
			&& game->map[game->e_y][game->e_x + 1] != 'B')
		game->e_x++;

}

void	ft_enemy_ai2(t_game *game)
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
	{
		ft_e_move_x(game);
	}
	else
	{
		ft_e_move_y(game);
	}
}

void	ft_enemy_ai(t_game *game)
{
	int		flow_x;
	int		flow_y;
	int		x;
	int		y;

	x = game->e_x;
	y = game->e_y;
	flow_x = game->e_x - game->p_x;
	flow_y = game->e_y - game->p_y;
	printf("p_x p_y : %d %d\n", game->p_x, game->p_y);
	if (flow_x < 0)
		flow_x = flow_x * -1;
	if (flow_y < 0)
		flow_y = flow_y * -1;
	if (flow_x > flow_y)
	{
		if (game->p_x < x)
		{
			printf("left\n");
			if (game->map[y][x - 1] != '1')
				game->e_x--;
			else if (game->e_py != (game->e_y - 1) && game->map[y - 1][x] != '1')
				game->e_y--;
			else if (game->e_py != (game->e_y + 1) && game->map[y + 1][x] != '1')
				game->e_y++;
			else
				game->e_x++;
		}
		else
		{
			printf("right\n");
			if (game->map[y][x + 1] != '1')
				game->e_x++;
			else if (game->e_py != (game->e_y - 1) && game->map[y - 1][x] != '1')
				game->e_y--;
			else if (game->e_py != (game->e_y + 1) && game->map[y + 1][x] != '1')
				game->e_y++;
			else
				game->e_x--;
		}
	}
	else
	{
		if (game->p_y < y)
		{
			printf("up\n");
			if (game->map[y - 1][x] != '1')
				game->e_y--;
			else if (game->e_px != (game->e_x - 1) && game->map[y][x - 1] != '1')
				game->e_x--;
			else if (game->e_px != (game->e_x + 1) && game->map[y][x + 1] != '1')
				game->e_x++;
			else
				game->e_y++;
		}
		else
		{
			printf("down\n");
			if (game->map[y + 1][x] != '1')
				game->e_y++;
			else if (game->e_px != (game->e_x - 1) && game->map[y][x - 1] != '1')
				game->e_x--;
			else if (game->e_px != (game->e_x + 1) && game->map[y][x + 1] != '1')
				game->e_x++;
			else
				game->e_y--;
		}
	}
	printf("e_x e_y : %d %d\n", game->e_x, game->e_y);
}

void	ft_move_enemy(t_game *game)
{
	if (game->enemy_timer > 30)
	{
		game->e_px = game->e_x;
		game->e_py = game->e_y;
		ft_enemy_ai2(game);
		game->enemy_timer = 0;
	}
	ft_enemy_collision(game);
}
