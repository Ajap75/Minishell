/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsalomon <fsalomon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 12:31:44 by fsalomon          #+#    #+#             */
/*   Updated: 2023/11/10 12:30:29 by fsalomon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*occ;
	int		len;
	int		i;

	len = 0;
	i = 0;
	while (s[len] != 0)
	{
		len ++;
	}
	if (c == 0)
	{
		occ = &((char *)s)[len];
		return (occ);
	}
	if (s[0] == (unsigned char )c)
		return (occ = (char *)s);
	while (s[i] != (unsigned char)c && s[i] != 0)
		i ++;
	occ = ((char *)s + i);
	if (s[i] == 0)
		occ = NULL;
	return ((char *)occ);
}
/*
 #include <stdio.h> 
int main ()
{
	char s[] = "tripouille";
	printf("%p \n", ft_strchr(s, 't' + 256));
	printf("%s \n", ft_strchr(s, 't' + 256));

	printf("%p \n",s);
	printf("%s \n",s);

	return (0);
} */