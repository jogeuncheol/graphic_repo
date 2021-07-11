/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gejo <gejo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/11 23:34:14 by gejo              #+#    #+#             */
/*   Updated: 2021/07/12 00:19:31 by gejo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

typedef struct s_map
{
	int		x;
	int		y;
	int		c;
	int		e;
	int		p;
	char	*m_str;
}	t_map;

typedef struct s_game
{
	int x;
	int y;
	char **map;
}

char *ft_map_str(char *map_file)
{
	int fd;
	char *tmp;
	char *m_str;
	char buff[2];
	
	m_str = NULL;
	fd = open(map_file, O_RDONLY);
	while (read(fd, buff, 1) > 0)
	{
		buff[1] = '\0';
		tmp = ft_strjoin(m_str, buff);
		free(m_str);
		m_str = NULL;
		m_str = tmp;
	}
	printf("%s", m_str);
	return (m_str);
}

int ft_check_1st_line(char *m_str)
{
	int i;

	i = 0;
	while (m_str[i] != '\n')
	{
		if (m_str[i] == '1')
			i++;
		else
			return (0);
	}
	return (1);
}

int ft_check_line(char *m_str)
{
	int i;
	int valid_line;

	i = 0;
	while (m_str[i] != '\0')
	{
		valid_line = 0;
		if (m_str[i] == '\n' && m_str[i + 1] != '\0')
		{
			if (m_str[i - 1] == '1' && m_str[i + 1] == '1')
				valid_line = 1;
			if (valid_line != 1)
				return (0);
		}
		i++;
	}
	return (1);
}

int ft_check_length_line(char *m_str)
{
	int i;
	int j;
	int len;

	i = 0;
	while (m_str[i] != '\n')
		i++;
	len = i++;
	while (m_str[i] != '\0')
	{
		j = 0;
		while (m_str[i] != '\n' && m_str[i] != '\0')
		{
			i++;
			j++;
		}
		if (j != len)
			return (0);
		if (m_str[i] == '\0')
			break ;
		i++;
	}
	return (1);
}

int ft_check_last_line(char *m_str)
{
	int i;

	i = 0;
	while (m_str[i + 1] != '\0')
		i++;
	if (m_str[i] == '\n')
		i--;
	while (m_str[i] != '\n')
	{
		if (m_str[i] == '1')
			i--;
		else
			return (0);
	}
	return (1);
}

int ft_map_close_check(t_map *map)
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
					printf("last line check fail\n");
			}
			else
				printf("line length check fail\n");
		}
		else
			printf("line check fail\n");
	}
	else
		printf("1st line check fail\n");
	return (0);
}

t_map *ft_map_parse(char *map_file)
{
	t_map *map;

	map = malloc(sizeof(t_map));
	if (map == NULL)
		return (NULL);
	map->m_str = ft_map_str(map_file);
	if (map->m_str == NULL)
	{
		printf("malloc fail\n");
		exit(1);
	}
	if (ft_map_close_check(map) == 1)
		printf("map valid check pass\n");
	return (map);
}

void ft_game(char *map_file)
{
	t_map *map;
	t_game *game;
	map = ft_map_parse(map_file);
	if (map == NULL)
	{
		printf("malloc fail\n");
		exit(1);
	}
	
}

int main(int argc, char *argv[])
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
