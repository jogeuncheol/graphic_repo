/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_texture_validation.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gejo <gejo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/17 19:15:25 by gejo              #+#    #+#             */
/*   Updated: 2021/07/17 19:39:07 by gejo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int		ft_player_tex_valid(t_game *game)
{
	int		invalid;

	invalid = 0;
	if (game->tex_player.img == NULL
			|| game->tex_player.img_2 == NULL
			|| game->tex_player.img_3 == NULL
			|| game->tex_player.c_img1 == NULL
			|| game->tex_player.c_img2 == NULL
			|| game->tex_player.c_img3 == NULL)
	{
		invalid = 1;
		ft_putstr_fd("Error\nplayer texture load fail\n", 2);
	}
	return (invalid);
}

int		ft_collect_tex_valid(t_game *game)
{
	int		invalid;

	invalid = 0;
	if (game->tex_collect.img == NULL
			|| game->tex_collect.img_2 == NULL
			|| game->tex_collect.img_3 == NULL
			|| game->tex_collect.img_4 == NULL
			|| game->tex_collect.c_img1 == NULL
			|| game->tex_collect.c_img2 == NULL
			|| game->tex_collect.c_img3 == NULL)
	{
		invalid = 1;
		ft_putstr_fd("Error\ncollect texture load fail\n", 2);
	}
	return (invalid);
}

int		ft_exit_tex_valid(t_game *game)
{
	int		invalid;

	invalid = 0;
	if (game->tex_exit.img == NULL
			|| game->tex_exit.img_2 == NULL
			|| game->tex_exit.img_3 == NULL
			|| game->tex_exit.img_4 == NULL
			|| game->tex_exit.c_img1 == NULL
			|| game->tex_exit.c_img2 == NULL
			|| game->tex_exit.c_img3 == NULL)
	{
		invalid = 1;
		ft_putstr_fd("Error\nexit texture load fail\n", 2);
	}
	return (invalid);
}

int		ft_texture_validation(t_game *game)
{
	int		invalid;

	invalid = 0;
	if (game->tex_wall.img == NULL)
	{
		invalid = 1;
		ft_putstr_fd("Error\nwall texture load fail\n", 2);
	}
	if (game->tex_tile.img == NULL)
	{
		invalid = 1;
		ft_putstr_fd("Error\ntile texture load fail\n", 2);
	}
	if (game->tex_stone.img == NULL)
	{
		invalid = 1;
		ft_putstr_fd("Error\nstone texture load fail\n", 2);
	}
	if (ft_player_tex_valid(game) == 1)
		invalid = 1;
	if (ft_collect_tex_valid(game) == 1)
		invalid = 1;
	if (ft_exit_tex_valid(game) == 1)
		invalid = 1;
	return (invalid);
}
