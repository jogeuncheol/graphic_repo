/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_exit_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gejo <gejo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/16 13:49:35 by gejo              #+#    #+#             */
/*   Updated: 2021/07/16 17:11:27 by gejo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_bonus.h"

void	ft_exit_animation(t_game *game, int i, int j)
{
	int		timer;

	timer = game->sprite_timer;
	if (timer < 5 || timer > 70)
		mlx_put_image_to_window(game->mlx_ptr, game->mlx_win,
				game->tex_exit.img, j, i);
	else if (timer < 10 || timer > 65)
		mlx_put_image_to_window(game->mlx_ptr, game->mlx_win,
				game->tex_exit.img_2, j, i);
	else if (timer < 15 || timer > 60)
		mlx_put_image_to_window(game->mlx_ptr, game->mlx_win,
				game->tex_exit.img_3, j, i);
	else if (timer < 20 || timer > 55)
		mlx_put_image_to_window(game->mlx_ptr, game->mlx_win,
				game->tex_exit.img_4, j, i);
	else if (timer < 25 || timer > 50)
		mlx_put_image_to_window(game->mlx_ptr, game->mlx_win,
				game->tex_exit.c_img1, j, i);
	else if (timer < 30 || timer > 45)
		mlx_put_image_to_window(game->mlx_ptr, game->mlx_win,
				game->tex_exit.c_img2, j, i);
	else
		mlx_put_image_to_window(game->mlx_ptr, game->mlx_win,
				game->tex_exit.c_img3, j, i);
}

void	ft_draw_exit(t_game *game)
{
	int		i;
	int		j;

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
