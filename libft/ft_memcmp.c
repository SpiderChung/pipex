/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schung <schung@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 18:37:04 by schung            #+#    #+#             */
/*   Updated: 2021/12/01 19:30:32 by schung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/libft.h"

int	ft_memcmp(void *arr1, void *arr2, size_t len)
{
	size_t			i;
	unsigned char	*a1;
	unsigned char	*a2;

	i = 0;
	a1 = (unsigned char *)arr1;
	a2 = (unsigned char *)arr2;
	while (len)
	{
		if (a1[i] != a2[i])
			return (a1[i] - a2[i]);
		i++;
		len--;
	}
	return (0);
}
