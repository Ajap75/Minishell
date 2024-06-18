/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsalomon <fsalomon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 18:40:15 by fsalomon          #+#    #+#             */
/*   Updated: 2023/11/10 15:37:12 by fsalomon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*pointer;

	if (size * nmemb == 0)
	{
		pointer = malloc(0);
		if (!pointer)
			return (NULL);
		return (pointer);
	}
	else if ((nmemb * size) / size != nmemb)
		return (NULL);
	else
	{
		pointer = malloc(nmemb * size);
		if (!pointer)
			return (NULL);
		ft_bzero(pointer, nmemb * size);
		return (pointer);
	}
}

/*
#include <unistd.h>
#include <stdio.h>

int		main()
{
	void * p = ft_calloc(2, 2);
	char e[] = {0, 0, 0, 0};
	printf("%d \n",memcmp(p, e, 4));
	free (p);
	return (0);
	
}*/