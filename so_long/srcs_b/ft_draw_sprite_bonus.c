/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_sprite_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gejo <gejo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/16 13:47:13 by gejo              #+#    #+#             */
/*   Updated: 2021/07/16 21:51:07 by gejo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_bonus.h"

void	ft_animation_timer(t_game *game)
{
	if (game->sprite_timer > 75)
		game->sprite_timer = 0;
}

void	ft_sprite_animation(t_game *game, int i, int j)
{
	int		timer;

	timer = game->sprite_timer;
	if (timer < 5 || timer > 70)
		mlx_put_image_to_window(game->mlx_ptr, game->mlx_win,
			game->tex_collect.img, j, i);
	else if (timer < 10 || timer > 65)
		mlx_put_image_to_window(game->mlx_ptr, game->mlx_win,
			game->tex_collect.img_2, j, i);
	else if (timer < 15 || timer > 60)
		mlx_put_image_to_window(game->mlx_ptr, game->mlx_win,
			game->tex_collect.img_3, j, i);
	else if (timer < 20 || timer > 55)
		mlx_put_image_to_window(game->mlx_ptr, game->mlx_win,
			game->tex_collect.img_4, j, i);
	else if (timer < 25 || timer > 50)
		mlx_put_image_to_window(game->mlx_ptr, game->mlx_win,
			game->tex_collect.c_img1, j, i);
	else if (timer < 30 || timer > 45)
		mlx_put_image_to_window(game->mlx_ptr, game->mlx_win,
			game->tex_collect.c_img2, j, i);
	else
		mlx_put_image_to_window(game->mlx_ptr, game->mlx_win,
			game->tex_collect.c_img3, j, i);
	ft_animation_timer(game);
}

void	ft_draw_sprite(t_game *game)
{
	int		i;
	int		j;

	game->sprite_timer++;
	i = 0;
	while (game->map[i] != NULL)
	{
		j = 0;
		while (game->map[i][j] != '\0')
		{
			if (game->map[i][j] == 'C')
				ft_sprite_animation(game, i * TILE_SIZE, j * TILE_SIZE);
			j++;
		}
		i++;
	}
}
