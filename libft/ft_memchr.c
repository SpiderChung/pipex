/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schung <schung@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 19:30:22 by schung            #+#    #+#             */
/*   Updated: 2021/12/01 19:30:28 by schung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	i;
	char	*a;

	i = 0;
	a = (char *)s;
	while (i < n)
	{
		if (a[i] == (char)c)
			return ((char *)s + i);
		i++;
	}
	return (0);
}
