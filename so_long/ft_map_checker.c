/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_checker.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gejo <gejo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/16 12:45:47 by gejo              #+#    #+#             */
/*   Updated: 2021/07/16 12:47:26 by gejo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_check_1st_line(char *m_str)
{
	int		i;

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

int	ft_check_map_char(char c)
{
	if (c == '0' || c== '1')
		return (1);
	else if (c == 'C' || c == 'P' || c == 'E')
		return (1);
	else
		return (0);
}

int	ft_check_line(char *m_str)
{
	int		i;
	int		valid_line;

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
		else if (m_str[i] != '\n' && ft_check_map_char(m_str[i]) == 0)
			return (0);
		i++;
	}
	return (1);
}

int	ft_check_length_line(char *m_str)
{
	int		i;
	int		j;
	int		len;

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

int	ft_check_last_line(char *m_str)
{
	int		i;

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