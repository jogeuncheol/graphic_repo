/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_open_read_file.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gejo <gejo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/16 20:30:21 by gejo              #+#    #+#             */
/*   Updated: 2021/07/16 21:43:33 by gejo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

char	*ft_read_file(int fd)
{
	char	buff[2];
	char	*m_str;
	char	*tmp;

	tmp = NULL;
	m_str = NULL;
	while (read(fd, buff, 1) > 0)
	{
		buff[1] = '\0';
		tmp = ft_strjoin(m_str, buff);
		free(m_str);
		if (tmp == NULL)
		{
			ft_putstr_fd("Error\nopen file malloc fail\n", 2);
			close(fd);
			return (NULL);
		}
		m_str = tmp;
	}
	close(fd);
	return (m_str);
}

char	*ft_open_file(char *map_file)
{
	int		fd;

	fd = open(map_file, O_RDONLY);
	if (fd == -1)
	{
		ft_putstr_fd("Error\nopen fail\n", 2);
		return (NULL);
	}
	return (ft_read_file(fd));
}
