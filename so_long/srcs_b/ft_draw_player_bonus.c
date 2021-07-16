/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_player_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gejo <gejo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/16 13:50:28 by gejo              #+#    #+#             */
/*   Updated: 2021/07/16 17:11:30 by gejo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_bonus.h"

void	ft_player_stone_switch(t_game *game, int timer)
{
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
}

void	ft_player_animation(t_game *game)
{
	int		timer;

	timer = game->player_timer;
	ft_player_stone_switch(game, timer);
	if (timer > 30)
		game->player_timer = 0;
}

void	ft_draw_player(t_game *game)
{
	game->player_timer++;
	ft_player_animation(game);
}
