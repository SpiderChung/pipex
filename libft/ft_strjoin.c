/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schung <schung@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 16:00:17 by schung            #+#    #+#             */
/*   Updated: 2021/12/01 19:21:36 by schung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char			*res;
	unsigned int	len;
	unsigned int	i;
	unsigned int	k;

	if (!s1 || !s2)
		return (NULL);
	k = ft_strlen(s1);
	len = k + ft_strlen(s2);
	res = (char *)malloc(sizeof(char) * (len + 1));
	if (!res)
		return (NULL);
	i = 0;
	while (i < k)
	{
		res[i] = s1[i];
		i++;
	}
	while (i < len)
	{
		res[i] = *s2++;
		i++;
	}
	res[len] = '\0';
	return (res);
}
