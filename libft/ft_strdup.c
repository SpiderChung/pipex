/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schung <schung@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 19:43:11 by schung            #+#    #+#             */
/*   Updated: 2021/12/01 19:22:11 by schung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/libft.h"

char	*ft_strdup(const char *s1)
{
	char	*a;
	int		len;
	int		i;

	len = ft_strlen(s1);
	i = 0;
	a = (char *)malloc((len + 1) * sizeof(char));
	if (!a)
		return (NULL);
	while (i < len)
	{
		a[i] = s1[i];
		i++;
	}
	a[len] = '\0';
	return (a);
}
