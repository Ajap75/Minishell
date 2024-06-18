/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsalomon <fsalomon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 12:17:20 by fsalomon          #+#    #+#             */
/*   Updated: 2023/11/09 12:12:26 by fsalomon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dst_len;
	size_t	src_len;
	size_t	i;

	i = 0;
	src_len = ft_strlen(src);
	if (!dst && size == 0)
		return (src_len);
	dst_len = 0;
	while (dst[dst_len] && dst_len < size)
		dst_len ++;
	if (size <= dst_len)
		return (src_len + dst_len);
	else
	{
		while (i < size - dst_len - 1 && src[i] != 0)
		{
			dst[dst_len + i] = src[i];
			i ++;
		}
	}
	dst[dst_len + i] = 0;
	return (dst_len + src_len);
}
