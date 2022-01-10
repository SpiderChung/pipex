/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schung <schung@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 12:02:08 by schung            #+#    #+#             */
/*   Updated: 2021/12/01 19:30:56 by schung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/libft.h"

void	throwaway(int n, int fd)
{
	if (n == -2147483648)
		ft_putstr_fd("-2147483648", fd);
	else
		ft_putchar_fd('0', fd);
}

void	ft_putnbr_fd(int n, int fd)
{
	char	dst[10];
	int		i;

	i = 0;
	if ((n == -2147483648) || (n == 0))
		return (throwaway(n, fd));
	if (n < 0)
	{
		write(fd, "-", 1);
		n = n * (-1);
	}
	while (n)
	{
		dst[i] = n % 10 + '0';
		n = n / 10;
		i++;
	}
	i--;
	while (i >= 0)
		ft_putchar_fd(dst[i--], fd);
}
