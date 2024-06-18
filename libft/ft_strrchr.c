/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsalomon <fsalomon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 12:38:17 by fsalomon          #+#    #+#             */
/*   Updated: 2023/11/10 12:31:48 by fsalomon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*occ;
	int		i;

	i = 0;
	while (s[i] != 0)
	{
		i ++;
	}
	occ = NULL;
	if (c == 0)
	{
		occ = &((char *)s)[i];
		return (occ);
	}
	while (*s != 0)
	{
		if (*s == (unsigned char)c)
		{
			occ = ((char *)s);
		}
		s ++;
	}
	return (occ);
}
/*
 #include <stdio.h> 
int main ()
{
	char s[] = "tripouille";
	printf("%p \n", ft_strrchr(s, 't' + 256));
	printf("%s \n", ft_strrchr(s, 't' + 256));

	printf("%p \n",s);
	printf("%s \n",s);

	return (0);
}*/