/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_validation.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gejo <gejo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/16 12:41:02 by gejo              #+#    #+#             */
/*   Updated: 2021/07/16 18:47:43 by gejo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	ft_file_name(char *map_file)
{
	int		i;

	i = 0;
	while (map_file[i] != '\0')
		i++;
	if (map_file[i - 1] == 'r' && map_file[i - 2] == 'e'
		&& map_file[i - 3] == 'b' && map_file[i - 4] == '.')
		return (1);
	return (0);
}

char	*ft_map_str(char *map_file)
{
	int		fd;
	char	*tmp;
	char	*m_str;
	char	buff[2];

	m_str = NULL;
	tmp = NULL;
	fd = open(map_file, O_RDONLY);
	if (fd == -1)
	{
		ft_putstr_fd("Error\nopen fail\n", 2);
		return (NULL);
	}
	while (read(fd, buff, 1) > 0)
	{
		buff[1] = '\0';
		tmp = ft_strjoin(m_str, buff);
		if (tmp == NULL)
		{
			ft_putstr_fd("Error\nopen file malloc fail\n", 2);
			free(m_str);
			return (NULL);
		}
		free(m_str);
		m_str = tmp;
	}
	return (m_str);
}

int	ft_exist_data(t_map *map)
{
	int		i;

	map->p = 0;
	map->e = 0;
	map->c = 0;
	i = 0;
	while (map->m_str[i] != '\0')
	{
		if (map->m_str[i] == 'C')
			map->c++;
		else if (map->m_str[i] == 'E')
			map->e++;
		else if (map->m_str[i] == 'P')
			map->p++;
		i++;
	}
	if (map->p != 1)
		return (0);
	else if (map->c < 1 || map->e < 1)
		return (0);
	return (1);
}

int	ft_map_close_check(t_map *map)
{
	if (ft_check_1st_line(map->m_str) == 1)
	{
		if (ft_check_line(map->m_str) == 1)
		{
			if (ft_check_length_line(map->m_str) == 1)
			{
				if (ft_check_last_line(map->m_str) == 1)
					return (1);
				else
					ft_putstr_fd("Error\nlast line check fail\n", 2);
			}
			else
				ft_putstr_fd("Error\nline length check fail\n", 2);
		}
		else
			ft_putstr_fd("Error\nline check fail\n", 2);
	}
	else
		ft_putstr_fd("Error\n1st line check fail\n", 2);
	return (0);
}

t_map	*ft_map_validation(char *map_file)
{
	t_map	*map;

	map = malloc(sizeof(t_map));
	if (map == NULL)
		return (NULL);
	map->m_str = ft_map_str(map_file);
	if (map->m_str == NULL)
	{
		ft_putstr_fd("Error\nmalloc fail\n", 2);
		ft_error(map, NULL);
	}
	if (ft_map_close_check(map) != 1)
	{
		ft_putstr_fd("Error\nmap invalid\n", 2);
		ft_error(map, NULL);
	}
	if (ft_exist_data(map) != 1)
	{
		ft_putstr_fd("Error\ngame data invalid\n", 2);
		ft_error(map, NULL);
	}
	return (map);
}
