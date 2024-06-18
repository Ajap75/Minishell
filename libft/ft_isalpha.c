/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsalomon <fsalomon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 11:22:34 by fsalomon          #+#    #+#             */
/*   Updated: 2023/11/07 19:03:58 by fsalomon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalpha(int c)
{
	if (c > 64)
	{
		if (c < 91)
			return (1);
		if (c > 96 && c < 123)
			return (1);
	}
	return (0);
}
/*
#include <stdio.h>

int main ()
{
    int test1 = 97;
    int test2 = 122;
    int test3 = 90;
    int test4 = 65;
    int test5 = 32;
    int test6 = 37;
    int test7 = 94;

    printf(" %c = %d \n", test1, ft_isalpha(test1));
    printf(" %c = %d \n", test2, ft_isalpha(test2));
    printf(" %c = %d \n", test3, ft_isalpha(test3));
    printf(" %c = %d \n", test4, ft_isalpha(test4));
    printf(" %c = %d \n", test5, ft_isalpha(test5));
    printf(" %c = %d \n", test6, ft_isalpha(test6));
    printf(" %c = %d \n", test7, ft_isalpha(test7));
    return (0);
}*/