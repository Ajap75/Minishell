/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsalomon <fsalomon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 14:56:24 by fsalomon          #+#    #+#             */
/*   Updated: 2023/11/21 10:18:30 by fsalomon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	little_len;

	j = 0;
	if (little[0] == 0 || big == little)
		return (((char *)big));
	if (len == 0)
		return (0);
	little_len = ft_strlen(little);
	while (big[j] != 0 && j < len)
	{
		i = 0;
		if (big[j] == little[i])
		{
			while (big[j + i] == little[i] && j + i < len && big[j + i] != 0)
				i ++;
			if (i == (little_len))
				return (&((char *)big)[j]);
		}
		j ++;
	}
	return (0);
}
/*
#include <bsd/string.h>

int main()
{
	printf("%s\n",ft_strnstr(NULL, "fake", 0));
	return (0);
}
*/