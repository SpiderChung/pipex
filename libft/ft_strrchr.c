/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schung <schung@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 22:06:22 by schung            #+#    #+#             */
/*   Updated: 2021/12/01 19:20:31 by schung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*r;

	r = (char *)s;
	i = ft_strlen(r);
	while (i >= 0)
	{
		if (r[i] == (char)c)
			return (r + i);
		i--;
	}
	return (0);
}
