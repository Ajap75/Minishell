/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsalomon <fsalomon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 15:16:20 by fsalomon          #+#    #+#             */
/*   Updated: 2023/11/21 10:19:17 by fsalomon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	int	sign;
	int	total;
	int	i;

	sign = 1;
	total = 0;
	i = 0;
	while ((nptr[i] > 8 && nptr[i] < 14) || nptr[i] == 32)
		i ++;
	if (nptr[i] == '+' || nptr[i] == '-' )
	{
		if (nptr[i] == '-')
		{
			sign = -sign;
		}
		i ++;
	}
	while (nptr[i] != 0 && nptr[i] > 47 && nptr[i] < 58)
	{
		total = total * 10 + (nptr[i] - '0');
		i ++;
	}
	total *= sign;
	return (total);
}

/* 
void	ft_print_result2(char c)
{
	write(1, &c, 1);
}

void	ft_print_result(int n)
{
	if (n >= 0)
	{
		if (n >= 10)
			ft_print_result(n / 10);
		ft_print_result2(n % 10 + '0');
	}
	else
	{
		ft_print_result2('-');
		if (n <= -10)
			ft_print_result(n / -10);
		ft_print_result2(n % -10 * -1 + '0');
	}
}

 int main ()
{
		ft_print_result(ft_atoi("\t\n\r\v\f  469 \n"));			return (0);
}  */