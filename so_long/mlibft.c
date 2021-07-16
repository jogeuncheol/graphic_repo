#include "so_long.h"

int	ft_strlen(char *str)
{
	int		i;

	if (str == NULL)
		return (0);
	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

void	ft_putstr_fd(char *str, int fd)
{
	int		i;

	i = 0;
	while (str[i] != '\0')
	{
		ft_putchar_fd(str[i], fd);
		i++;
	}
}

char	*ft_strdup(char *str)
{
	int		i;
	char	*ret;

	if (str == NULL)
		return (NULL);
	ret = malloc((ft_strlen(str) + 1) * sizeof(char));
	if (ret == NULL)
		return (NULL);
	i = 0;
	while (i < ft_strlen(str))
	{
		ret[i] = str[i];
		i++;
	}
	ret[i] = '\0';
	return (ret);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	int		len;
	char	*ret;

	if (s1 == NULL && s2 != NULL)
		return (ft_strdup(s2));
	else if (s1 != NULL && s2 == NULL)
		return (ft_strdup(s1));
	len = ft_strlen(s1) + ft_strlen(s2);
	ret = malloc((len + 1) * sizeof(char));
	if (ret == NULL)
		return (NULL);
	i = 0;
	while (s1[i] != '\0')
	{
		ret[i] = s1[i];
		i++;
	}
	while (s2[i - ft_strlen(s1)] != '\0')
	{
		ret[i] = s2[i - ft_strlen(s1)];
		i++;
	}
	ret[i] = '\0';
	return (ret);
}
