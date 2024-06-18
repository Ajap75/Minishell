/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsalomon <fsalomon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 15:39:19 by fsalomon          #+#    #+#             */
/*   Updated: 2023/11/14 15:43:44 by fsalomon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_putdigits(int n, int fd)
{
	char	c;

	c = n + 48;
	write(fd, &c, 1);
}

static int	ft_digits_nb(long nb)
{
	int	digits_nb;

	digits_nb = 1;
	while ((nb / 10) > 0)
	{
		digits_nb ++;
		nb /= 10;
	}
	return (digits_nb);
}		

void	ft_putnbr_fd(int n, int fd)
{
	int			i;
	int			j;
	int			divisor;
	long		nb2;

	nb2 = n;
	i = 0;
	if (nb2 < 0)
	{
		write(fd, "-", 1);
		nb2 = -nb2;
	}
	while (i < ft_digits_nb(nb2))
	{
		j = 0;
		divisor = 1;
		while (j + i < (ft_digits_nb(nb2) - 1))
		{
			divisor *= 10;
			j ++;
		}
		ft_putdigits((nb2 / divisor) % 10, fd);
		i ++;
	}
}
