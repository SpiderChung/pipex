/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schung <schung@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 19:35:38 by schung            #+#    #+#             */
/*   Updated: 2021/12/01 19:21:26 by schung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;
	size_t	len_dst;
	size_t	len_src;
	size_t	res;

	i = 0;
	len_dst = ft_strlen((char *)dst);
	len_src = ft_strlen((char *)src);
	if (len_dst > dstsize)
		res = dstsize + len_src;
	else
		res = len_dst + len_src;
	j = len_dst;
	if ((len_dst + 1 < dstsize) && (dstsize > 0))
	{
		while ((src[i]) && (len_dst + i + 1 < dstsize))
		{	
			dst[j] = src[i];
			j++;
			i++;
		}
		dst[j] = '\0';
	}
	return (res);
}	
