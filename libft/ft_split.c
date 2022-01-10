/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schung <schung@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 12:00:51 by schung            #+#    #+#             */
/*   Updated: 2021/12/01 19:22:35 by schung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/libft.h"

int	free_lines(char **src, int size)
{
	while (size >= 0)
	{
		free(src[size]);
		size--;
	}
	free(src);
	return (0);
}

int	word_len(char const *s, char c)
{
	int	i;
	int	len;

	len = 0;
	i = 0;
	while ((s[i] != c) && (s[i] != '\0'))
	{
		len++;
		i++;
	}
	return (len);
}

int	counter_line(char const *src, char c)
{
	unsigned int	i;
	unsigned int	len;

	len = 0;
	i = 0;
	while (src[i] != '\0')
	{
		while (src[i] == c)
			i++;
		if ((src[i] != c) && (src[i] != '\0'))
			len++;
		while ((src[i] != c) && (src[i] != '\0'))
			i++;
	}
	return (len);
}

int	write_lines(char **dest, char const *src, char c, unsigned int word_count)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	len;

	i = 0;
	j = 0;
	while (j < word_count)
	{	
		while (src[i] == c)
			i++;
		len = word_len(&src[i], c);
		dest[j] = ft_substr(src, i, len);
		if (!dest[j])
			return (free_lines(dest, j));
		while ((src[i] != c) && (src[i] != '\0'))
			i++;
		j++;
	}
	return (1);
}

char	**ft_split(char const *s, char c)
{
	unsigned int	i;
	unsigned int	len;
	char			**res;

	if (!s)
		return (NULL);
	len = counter_line(s, c);
	res = (char **)malloc(sizeof(char *) * (len + 1));
	if (!res)
		return (NULL);
	i = 0;
	if (write_lines(res, s, c, len) == 0)
		return (NULL);
	res[len] = 0;
	return (res);
}
