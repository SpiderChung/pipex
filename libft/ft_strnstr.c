/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schung <schung@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 19:44:01 by schung            #+#    #+#             */
/*   Updated: 2021/12/01 19:20:43 by schung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	dl;

	i = 0;
	dl = ft_strlen(needle);
	if ((dl == 0) || haystack == needle)
		return ((char *)haystack);
	while ((haystack[i] != '\0') && (len > i))
	{
		j = 0;
		while (needle[j] != '\0' && haystack[i + j] == needle[j]
			&& (i + j) < len && haystack[i + j] != '\0')
		{
			j++;
		}
		if (j == dl)
			return ((char *)haystack + i);
		i++;
	}
	return (0);
}
