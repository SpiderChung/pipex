/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schung <schung@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 19:19:04 by schung            #+#    #+#             */
/*   Updated: 2021/12/26 12:59:57 by schung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/libft.h"

static char	*ft_strjoin_gnl(char *s1, char *s2)
{
	char	*res;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (!s1 || !s2)
		return (NULL);
	res = malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!res)
		return (NULL);
	while (s1[i] != '\0')
	{
		res[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
	{
		res[i + j] = s2[j];
		j++;
	}
	res[i + j] = '\0';
	free(s1);
	return (res);
}

static char	*ft_strdup_gnl(const char *s1)
{
	char	*a;
	int		i;

	i = 0;
	if (!(s1[i]))
		return (NULL);
	while (s1[i] && s1[i] != '\n')
		i++;
	a = (char *)malloc((i + 2) * sizeof(char));
	if (!a)
		return (NULL);
	i = 0;
	while (s1[i] && s1[i] != '\n')
	{
		a[i] = s1[i];
		i++;
	}
	if (s1[i] == '\n')
	{
		a[i] = s1[i];
		i++;
	}
	a[i] = '\0';
	return (a);
}

char static	*ft_new_rest(char *src)
{
	int		i;
	int		j;
	char	*dest;

	i = 0;
	while (src[i] && src[i] != '\n')
		i++;
	if (!src[i])
	{
		free(src);
		return (NULL);
	}
	dest = (char *)malloc(sizeof(char) * (ft_strlen(src) - i + 1));
	if (!dest)
		return (NULL);
	i++;
	j = 0;
	while (src[i])
		dest[j++] = src[i++];
	dest[j] = '\0';
	free(src);
	return (dest);
}

static char	*rest_check(char *src)
{
	if (!src)
	{
		src = malloc(sizeof(char) * 1);
		src[0] = '\0';
	}
	return (src);
}

char	*get_next_line(int fd)
{
	char		buff[BUFFER_SIZE + 1];
	char		*dest;
	static char	*rest;
	int			quantity;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd > 256)
		return (0);
	quantity = 1;
	rest = rest_check(rest);
	while (!(ft_strchr(rest, '\n')) && quantity != 0)
	{
		quantity = read(fd, buff, BUFFER_SIZE);
		if (quantity == -1)
		{
			free(rest);
			return (NULL);
		}
		buff[quantity] = '\0';
		rest = ft_strjoin_gnl(rest, buff);
	}
	dest = ft_strdup_gnl(rest);
	rest = ft_new_rest(rest);
	return (dest);
}
