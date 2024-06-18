/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsalomon <fsalomon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 12:02:38 by fsalomon          #+#    #+#             */
/*   Updated: 2023/11/07 15:43:20 by fsalomon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		((char *)s)[i] = c;
		i ++;
	}
	return (s);
}

/*
#include <stdio.h>
#include <string.h>

int main ()
{
	int array[5];
	size_t size = sizeof(int) * 5;
	size_t i = 0;
	int c = 12;

	array[0] = 54;
	array[1] = 554;
	array[2] = 5554;
	array[3] = 55554;
	array[4] = 555554;
	while (i < 5)
	{
		printf("%d \n",array[i]);
		i++;
	}
	ft_memset(array, c, size);
	i = 0;
	while (i < 5)
	{
		printf("%d \n",array[i]);
		i++;
	}
		array[0] = 54;
	array[1] = 554;
	array[2] = 5554;
	array[3] = 55554;
	array[4] = 555554;
	i = 0;

		while (i < 5)
	{
		printf("%d \n",array[i]);
		i++;
	}
	memset(array, c, size);
	i = 0;
	while (i < 5)
	{
		printf("%d \n",array[i]);
		i++;
	}

	return (0);
}*/