/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_game.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gejo <gejo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/16 12:57:29 by gejo              #+#    #+#             */
/*   Updated: 2021/07/16 17:01:05 by gejo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_init_map_xy(t_game *game, char *m_str)
{
	int		i;
	int		line;

	i = 0;
	while (m_str[i] != '\n')
		i++;
	game->x = i;
	line = 1;
	while (m_str[i + 1] != '\0')
	{
		if (m_str[i] == '\n')
			line++;
		i++;
	}
	game->y = line;
}

void	ft_init_map(t_map *map, t_game *game)
{
	int		i;
	int		idx;
	char	*tmp;

	ft_init_map_xy(game, map->m_str);
	game->map = malloc((game->y + 1) * sizeof(char *));
	if (game->map == NULL)
	{
		ft_putstr_fd("Error\nmap malloc fail\n", 2);
		ft_error(map, game);
	}
	i = 0;
	idx = 0;
	tmp = &(map->m_str[i]);
	while (map->m_str[i] != '\0')
	{
		if (map->m_str[i] == '\n')
		{
			map->m_str[i] = '\0';
			game->map[idx] = ft_strdup(tmp);
			map->m_str[i] = '\n';
			if (game->map[idx] == NULL)
			{
				game->map[idx + 1] = NULL;
				ft_error(map, game);
			}
			idx++;
			tmp = &(map->m_str[i + 1]);
		}
		i++;
	}
	game->map[idx] = NULL;
}

void	ft_backup_map(t_map *map, t_game *game)
{
	int		i;
	int		j;
	char	*tmp;

	game->map_backup = malloc((game->y + 1) * sizeof(char *));
	if (game->map_backup == NULL)
	{
		ft_putstr_fd("Error\nmap backup malloc fail\n", 2);
		ft_error(map, game);
	}
	i = 0;
	while (game->map[i] != NULL)
	{
		game->map_backup[i] = ft_strdup(game->map[i]);
		if (game->map_backup[i] == NULL)
		{
			game->map_backup[i + 1] = NULL;
			ft_putstr_fd("Error\nmap backup fail\n", 2);
			ft_error(map, game);
		}
		i++;
	}
	game->map_backup[i] = NULL;
}

t_game	*ft_set_game(t_map *map)
{
	t_game	*game;
	
	game = malloc(sizeof(t_game));
	if (game == NULL)
		return (NULL);
	ft_init_map(map, game);
	ft_backup_map(map, game);
	return (game);
}
