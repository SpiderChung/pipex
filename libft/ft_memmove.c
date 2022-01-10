/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schung <schung@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 19:29:56 by schung            #+#    #+#             */
/*   Updated: 2021/12/01 19:30:42 by schung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	i;
	char	*a1;
	char	*a2;

	if (!dst && !src)
		return (NULL);
	a1 = (char *)dst;
	a2 = (char *)src;
	if (src < dst)
	{	
		i = len;
		while (i-- > 0)
			a1[i] = a2[i];
	}
	else
	{
		i = 0;
		while (i < len)
		{
			a1[i] = a2[i];
			i++;
		}
	}
	return (dst);
}
