/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schung <schung@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 16:55:40 by schung            #+#    #+#             */
/*   Updated: 2021/12/01 19:22:49 by schung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	*r;

	i = 0;
	r = (char *)s;
	while (r[i] != (char)c)
	{
		if (r[i] == '\0')
			return (0);
		i++;
	}
	return (r + i);
}
