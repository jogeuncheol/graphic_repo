/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_screen.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gejo <gejo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/16 13:37:16 by gejo              #+#    #+#             */
/*   Updated: 2021/07/16 17:10:28 by gejo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	ft_draw_screen(t_game *game)
{
	int		i;
	int		j;

	i = 0;
	while (game->map[i] != NULL)
	{
		j = 0;
		while (game->map[i][j] != '\0')
		{
			if (game->map[i][j] == '1')
				mlx_put_image_to_window(game->mlx_ptr, game->mlx_win,
						game->tex_wall.img, j * TILE_SIZE, i * TILE_SIZE);
			else if (game->map[i][j] == 'B')
				mlx_put_image_to_window(game->mlx_ptr, game->mlx_win,
						game->tex_stone.img, j * TILE_SIZE, i * TILE_SIZE);
			else if (game->map[i][j] == 'E')
				mlx_put_image_to_window(game->mlx_ptr, game->mlx_win,
						game->tex_exit.img, j * TILE_SIZE, i * TILE_SIZE);
			else
				mlx_put_image_to_window(game->mlx_ptr, game->mlx_win,
						game->tex_tile.img, j * TILE_SIZE, i * TILE_SIZE);
			j++;
		}
		i++;
	}
}
