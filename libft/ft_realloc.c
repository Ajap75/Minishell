/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anastruc <anastruc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 12:41:52 by anastruc          #+#    #+#             */
/*   Updated: 2024/07/03 14:23:05 by anastruc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_realloc(void *ptr, size_t size)
{
	void *new_memory_area;

	new_memory_area = malloc(size);

	if (!new_memory_area)
		return (NULL);
	if (ptr)
		ft_strlcpy(new_memory_area, ptr, ft_strlen(ptr));
	return(new_memory_area);
}