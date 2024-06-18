/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsalomon <fsalomon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 12:24:34 by fsalomon          #+#    #+#             */
/*   Updated: 2023/11/14 14:02:50 by fsalomon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_putdigits(int n, char *number, int index)
{
	char	c;

	c = n + 48;
	number[index] = c;
	return (number);
}

static long	ft_digits_nb(long nb)
{
	long	digits_nb;

	digits_nb = 1;
	while ((nb / 10) > 0)
	{
		digits_nb++;
		nb /= 10;
	}
	return (digits_nb);
}

static char	*ft_convert_digit(long nb2, int i, char *number, int neg)
{
	int	j;
	int	divisor;

	if (neg)
		i++;
	while ((i - neg) < ft_digits_nb(nb2))
	{
		j = 0;
		divisor = 1;
		while (j + (i - neg) < (ft_digits_nb(nb2) - 1))
		{
			divisor *= 10;
			j++;
		}
		ft_putdigits((nb2 / divisor) % 10, number, i);
		i++;
	}
	number[i] = 0;
	return (number);
}

char	*ft_itoa(int n)
{
	int		i;
	long	nb2;
	char	*number;
	int		neg;

	nb2 = n;
	neg = 0;
	i = 0;
	if (n < 0)
	{
		nb2 = -nb2;
		neg = 1;
	}
	number = malloc(sizeof(char) * ft_digits_nb(nb2) + 1 + neg);
	if (!number)
		return (NULL);
	if (neg)
		number[i] = '-';
	number = ft_convert_digit(nb2, i, number, neg);
	return (number);
}

/*  int main()
{
	printf("%s \n", ft_itoa(-2147483648));
	return (0);

}  */
