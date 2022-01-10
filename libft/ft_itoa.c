/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schung <schung@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 12:02:08 by schung            #+#    #+#             */
/*   Updated: 2021/12/01 19:25:55 by schung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/libft.h"

void	count_len(int n, unsigned int *len)
{
	while (n)
	{
		n = n / 10;
		*len = *len + 1;
	}
	if (*len == 0)
		*len = *len + 1;
}

void	minus_itoa(int *b, unsigned int *cons, unsigned int *dl)
{
	if (*b < 0)
	{
		*b = *b * -1;
		*cons = 1;
		*dl = *dl + 1;
	}
}

char	*ft_itoa(int n)
{
	unsigned int	minus;
	unsigned int	len;
	char			*dest;

	len = 0;
	minus = 0;
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	minus_itoa(&n, &minus, &len);
	count_len(n, &len);
	dest = (char *)malloc(sizeof(char) * len + 1);
	if (!dest)
		return (NULL);
	dest[len] = '\0';
	while (len--)
	{
		dest[len] = n % 10 + '0';
		n = n / 10;
	}
	if (minus)
		dest[0] = '-';
	return (dest);
}
