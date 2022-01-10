/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schung <schung@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 19:29:10 by schung            #+#    #+#             */
/*   Updated: 2021/12/01 19:30:37 by schung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;
	char	*a1;
	char	*a2;

	i = 0;
	a1 = (char *)dst;
	a2 = (char *)src;
	if (!n || dst == src)
		return (dst);
	while (i < n)
	{
		a1[i] = a2[i];
		i++;
	}
	return (dst);
}
