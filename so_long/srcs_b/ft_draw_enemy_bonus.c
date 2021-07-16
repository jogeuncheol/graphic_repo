/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_enemy.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gejo <gejo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/16 16:10:21 by gejo              #+#    #+#             */
/*   Updated: 2021/07/16 16:59:37 by gejo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_draw_enemy(t_game *game)
{
	game->enemy_timer++;
	mlx_put_image_to_window(game->mlx_ptr, game->mlx_win,
			game->tex_enemy.img, game->e_x * TILE_SIZE, game->e_y * TILE_SIZE);
}
