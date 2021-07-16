/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gejo <gejo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/16 12:00:25 by gejo              #+#    #+#             */
/*   Updated: 2021/07/16 17:10:37 by gejo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	ft_free_map(char **map)
{
	int		i;

	i = 0;
	while (map[i] != NULL)
	{
		free(map[i]);
		map[i] = NULL;
		i++;
	}
	free(map);
	map = NULL;
}

void	ft_destroy_mlx(t_game *game)
{
	mlx_destroy_image(game->mlx_ptr, game->tex_wall.img);
	mlx_destroy_image(game->mlx_ptr, game->tex_tile.img);
	mlx_destroy_image(game->mlx_ptr, game->tex_stone.img);
	mlx_destroy_image(game->mlx_ptr, game->tex_exit.img);
	mlx_destroy_image(game->mlx_ptr, game->tex_collect.c_img1);
	mlx_destroy_image(game->mlx_ptr, game->tex_collect.c_img2);
	mlx_destroy_image(game->mlx_ptr, game->tex_collect.c_img3);
	mlx_destroy_image(game->mlx_ptr, game->tex_collect.img);
	mlx_destroy_image(game->mlx_ptr, game->tex_collect.img_2);
	mlx_destroy_image(game->mlx_ptr, game->tex_collect.img_3);
	mlx_destroy_image(game->mlx_ptr, game->tex_collect.img_4);
	mlx_destroy_image(game->mlx_ptr, game->tex_player.img);
	mlx_destroy_image(game->mlx_ptr, game->tex_player.img_2);
	mlx_destroy_image(game->mlx_ptr, game->tex_player.img_3);
	mlx_destroy_window(game->mlx_ptr, game->mlx_win);
}
