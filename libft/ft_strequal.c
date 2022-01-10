/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequal.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schung <schung@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 19:21:46 by schung            #+#    #+#             */
/*   Updated: 2021/12/26 12:56:04 by schung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/libft.h"

int	ft_strequal(char const *s1, char const *s2)
{
	int	i;

	i = 0;
	if (s1 && s2)
	{
		if (ft_strcmp(s1, s2) == 0)
			return (1);
		return (0);
	}
	return (0);
}
