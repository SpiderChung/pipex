/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schung <schung@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 15:31:50 by schung            #+#    #+#             */
/*   Updated: 2021/12/01 19:19:54 by schung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/libft.h"

void	ft_compare(char const *src, size_t *len)
{
	size_t	l;

	l = ft_strlen(src);
	if (*len > l)
		*len = l;
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned int	i;
	unsigned int	count;
	char			*a;
	char			*b;

	if (!s)
		return (NULL);
	ft_compare(s, &len);
	b = (char *)s;
	a = (char *)malloc(sizeof(char) * (len + 1));
	if (!a)
		return (NULL);
	i = 0;
	count = 0;
	while (b[i])
	{
		if ((i >= start) && (count < len))
		{
			a[count] = b[i];
			count++;
		}
		i++;
	}
	a[count] = '\0';
	return (a);
}
