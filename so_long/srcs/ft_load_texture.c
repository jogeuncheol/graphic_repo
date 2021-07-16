/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_load_texture.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gejo <gejo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/16 12:17:32 by gejo              #+#    #+#             */
/*   Updated: 2021/07/16 17:10:46 by gejo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	ft_player_texture(t_game *game)
{
	game->tex_player.img =
		mlx_xpm_file_to_image(game->mlx_ptr, "./texture/player1.xpm",
		&game->tex_player.width, &game->tex_player.height);
	game->tex_player.data =
		(int *)mlx_get_data_addr(game->tex_player.img,
		&game->tex_player.bpp, &game->tex_player.size_l, &game->tex_player.endian);
	game->tex_player.img_2 =
		mlx_xpm_file_to_image(game->mlx_ptr, "./texture/player2.xpm",
		&game->tex_player.width, &game->tex_player.height);
	game->tex_player.img_3 =
		mlx_xpm_file_to_image(game->mlx_ptr, "./texture/player3.xpm",
		&game->tex_player.width, &game->tex_player.height);
	game->tex_player.c_img1 =
		mlx_xpm_file_to_image(game->mlx_ptr, "./texture/w_player1.xpm",
		&game->tex_player.width, &game->tex_player.height);
	game->tex_player.c_img2 =
		mlx_xpm_file_to_image(game->mlx_ptr, "./texture/w_player2.xpm",
		&game->tex_player.width, &game->tex_player.height);
	game->tex_player.c_img3 =
		mlx_xpm_file_to_image(game->mlx_ptr, "./texture/w_player3.xpm",
		&game->tex_player.width, &game->tex_player.height);
}

void	ft_collect_texture(t_game *game)
{
	game->tex_collect.img =
		mlx_xpm_file_to_image(game->mlx_ptr, "./texture/gold_01.xpm",
		&game->tex_collect.width, &game->tex_collect.height);
	game->tex_collect.data =
		(int *)mlx_get_data_addr(game->tex_collect.img,
		&game->tex_collect.bpp, &game->tex_collect.size_l, &game->tex_collect.endian);
	game->tex_collect.img_2 =
		mlx_xpm_file_to_image(game->mlx_ptr, "./texture/gold_02.xpm",
		&game->tex_collect.width, &game->tex_collect.height);
	game->tex_collect.img_3 =
		mlx_xpm_file_to_image(game->mlx_ptr, "./texture/gold_03.xpm",
		&game->tex_collect.width, &game->tex_collect.height);
	game->tex_collect.img_4 =
		mlx_xpm_file_to_image(game->mlx_ptr, "./texture/gold_04.xpm",
		&game->tex_collect.width, &game->tex_collect.height);
	game->tex_collect.c_img1 =
		mlx_xpm_file_to_image(game->mlx_ptr, "./texture/gold_05.xpm",
		&game->tex_collect.width, &game->tex_collect.height);
	game->tex_collect.c_img2 =
		mlx_xpm_file_to_image(game->mlx_ptr, "./texture/gold_06.xpm",
		&game->tex_collect.width, &game->tex_collect.height);
	game->tex_collect.c_img3 =
		mlx_xpm_file_to_image(game->mlx_ptr, "./texture/gold_07.xpm",
		&game->tex_collect.width, &game->tex_collect.height);
}

void	ft_exit_texture(t_game *game)
{
	game->tex_exit.img =
		mlx_xpm_file_to_image(game->mlx_ptr, "./texture/exit_01.xpm",
		&game->tex_exit.width, &game->tex_exit.height);
	game->tex_exit.data =
		(int *)mlx_get_data_addr(game->tex_exit.img,
		&game->tex_exit.bpp, &game->tex_exit.size_l, &game->tex_exit.endian);
	game->tex_exit.img_2 =
		mlx_xpm_file_to_image(game->mlx_ptr, "./texture/exit_02.xpm",
		&game->tex_exit.width, &game->tex_exit.height);
	game->tex_exit.img_3 =
		mlx_xpm_file_to_image(game->mlx_ptr, "./texture/exit_03.xpm",
		&game->tex_exit.width, &game->tex_exit.height);
	game->tex_exit.img_4 =
		mlx_xpm_file_to_image(game->mlx_ptr, "./texture/exit_04.xpm",
		&game->tex_exit.width, &game->tex_exit.height);
	game->tex_exit.c_img1 =
		mlx_xpm_file_to_image(game->mlx_ptr, "./texture/exit_05.xpm",
		&game->tex_exit.width, &game->tex_exit.height);
	game->tex_exit.c_img2 =
		mlx_xpm_file_to_image(game->mlx_ptr, "./texture/exit_06.xpm",
		&game->tex_exit.width, &game->tex_exit.height);
	game->tex_exit.c_img3 =
		mlx_xpm_file_to_image(game->mlx_ptr, "./texture/exit_07.xpm",
		&game->tex_exit.width, &game->tex_exit.height);
}

void	ft_load_texture(t_game *game)
{
	game->tex_wall.img =
		mlx_xpm_file_to_image(game->mlx_ptr, "./texture/wall.xpm",
		&game->tex_wall.width, &game->tex_wall.height);
	game->tex_wall.data =
		(int *)mlx_get_data_addr(game->tex_wall.img,
		&game->tex_wall.bpp, &game->tex_wall.size_l, &game->tex_wall.endian);
	game->tex_tile.img =
		mlx_xpm_file_to_image(game->mlx_ptr, "./texture/tile.xpm",
		&game->tex_tile.width, &game->tex_tile.height);
	game->tex_tile.data =
		(int *)mlx_get_data_addr(game->tex_tile.img,
		&game->tex_tile.bpp, &game->tex_tile.size_l, &game->tex_tile.endian);
	game->tex_stone.img =
		mlx_xpm_file_to_image(game->mlx_ptr, "./texture/b_stone.xpm",
		&game->tex_stone.width, &game->tex_stone.height);
	game->tex_stone.data =
		(int *)mlx_get_data_addr(game->tex_stone.img, &game->tex_stone.bpp,
		&game->tex_stone.size_l, &game->tex_stone.endian);
	ft_collect_texture(game);
	ft_player_texture(game);
	ft_exit_texture(game);
}
