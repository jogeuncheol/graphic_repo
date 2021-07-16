/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gejo <gejo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/16 12:35:17 by gejo              #+#    #+#             */
/*   Updated: 2021/07/16 13:06:40 by gejo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_error(t_map *map, t_game *game)
{
	if (map != NULL)
	{
		if (map->m_str != NULL)
			free(map->m_str);
		free(map);
	}
	if (game != NULL)
	{
		if (game->map != NULL)
			ft_free_map(game->map);
		if (game->map_backup != NULL)
			ft_free_map(game->map_backup);
		free(game);
	}
	exit(1);
}