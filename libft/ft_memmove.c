/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsalomon <fsalomon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 15:18:13 by fsalomon          #+#    #+#             */
/*   Updated: 2023/11/10 16:52:19 by fsalomon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t	i;

	i = 0;
	if ((char *)dest != (char *)src && n != 0)
	{
		if ((char *)dest > (char *)src)
		{
			i = n - 1;
			while (i > 0)
			{
				((char *)dest)[i] = ((char *)src)[i];
				i --;
			}
			((char *)dest)[i] = ((char *)src)[i];
		}
		else
		{
			while (i < n)
			{
				((char *)dest)[i] = ((char *)src)[i];
				i ++;
			}
		}	
	}
	return (dest);
}

/* 
int	main ()
{
	char	*src = "thanks to @apellicc for this test !\r\n";
	char	dst1[0xF0];
	int		size = strlen(src);
	char	*r1 = memmove(dst1, src, size);
	char	*r2 = ft_memmove(dst1, src, size);
	printf("%s \n", r1);
	printf("%s \n", r2);
	r2 = ft_memmove("", "" - 1, 0);
	r1 = memmove("", "" - 1, 0);

	printf("%s \n", r2);
	printf("%s \n", r1);
	return (0);
} */