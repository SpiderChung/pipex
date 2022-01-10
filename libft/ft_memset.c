/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schung <schung@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 19:28:20 by schung            #+#    #+#             */
/*   Updated: 2021/12/01 19:30:46 by schung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/libft.h"

void	*ft_memset(void *src, int c, size_t len)
{
	char	*a;

	a = src;
	while (len > 0)
	{
		*a = c;
		a++;
		len--;
	}
	return (src);
}
