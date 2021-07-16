/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gejo <gejo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/16 12:11:18 by gejo              #+#    #+#             */
/*   Updated: 2021/07/16 13:30:30 by gejo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_game_loop(t_game *game)
{
	if (game->exit_status == 0 && game->enemy_status == 0)
	{
		ft_draw_screen(game);
		ft_draw_sprite(game);
		ft_draw_exit(game);
		ft_draw_player(game);
//		ft_move_enemy(game);
//		ft_draw_enemy(game);
		ft_game_status(game);
	}
//	ft_enemy_count_manager(game);
	return (0);
}

void	ft_start_game(t_game *game)
{
	ft_init_game(game);
	mlx_hook(game->mlx_win, EVENT_KEY_RELEASE, 0, key_press, game);
	mlx_hook(game->mlx_win, EVENT_KEY_DESTROY_NOTIFY, 0, ft_game_close, game);
	mlx_loop_hook(game->mlx_ptr, &ft_game_loop, game);
	mlx_loop(game->mlx_ptr);
}

void	ft_game(char *map_file)
{
	t_map	*map;
	t_game	*game;

	if (ft_file_name(map_file) != 1)
	{
		ft_putstr_fd("Error\nfile name must end .ber\n", 2);
		exit(1);
	}
	map = ft_map_validation(map_file);
	if (map == NULL)
	{
		ft_putstr_fd("Error\nt_map malloc fail\n", 2);
		exit(1);
	}
	game = ft_set_game(map);
	if (game == NULL)
	{
		ft_putstr_fd("Error\nt_game malloc fail\n", 2);
		ft_error(map, NULL);
	}
	free(map->m_str);
	free(map);
	ft_start_game(game);
}

int	main(int argc, char *argv[])
{
	if (argc == 2)
		ft_game(argv[1]);
	else
	{
		printf("Error\n");
		exit(1);
	}
	return (0);
}
