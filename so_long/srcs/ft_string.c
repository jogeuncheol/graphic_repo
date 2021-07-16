/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gejo <gejo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/16 12:01:12 by gejo              #+#    #+#             */
/*   Updated: 2021/07/16 18:45:04 by gejo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

char	*set_nbr(char *nbr, int n, int len, int sign)
{
	int		i;

	i = 0;
	if (n == -2147483648)
	{
		nbr[len - i] = -(n % 10) + '0';
		n = n / 10;
		i++;
	}
	if (n < 0)
		n = n * -1;
	while (n / 10 != 0)
	{
		nbr[len - i] = (n % 10) + '0';
		n = n / 10;
		i++;
	}
	nbr[len - i++] = (n % 10) + '0';
	if (sign == 1)
		nbr[i] = '\0';
	else
		nbr[i + 1] = '\0';
	return (nbr);
}

char	*ft_itoa(int n)
{
	int		i;
	int		tmp;
	int		len;
	char	*nbr;

	i = 0;
	len = 0;
	tmp = n;
	while (tmp / 10 != 0)
	{
		tmp = tmp / 10;
		len++;
	}
	len++;
	if (n < 0)
	{
		nbr = malloc((len + 2) * sizeof(char));
		if (nbr == NULL)
			return (NULL);
		nbr[0] = '-';
		return (set_nbr(nbr, n, len, -1));
	}
	nbr = malloc((len + 1) * sizeof(char));
	if (nbr == NULL)
		return (NULL);
	return (set_nbr(nbr, n, len - 1, 1));
}

void	ft_str_move_count(t_game *game)
{
	char	*nbr;

	nbr = ft_itoa(game->move_count);
	if (nbr == NULL)
		ft_game_close(game);
	if (game->move_str != NULL)
		free(game->move_str);
	game->move_str = ft_strjoin("move : ", nbr);
	free(nbr);
	nbr = NULL;
}
