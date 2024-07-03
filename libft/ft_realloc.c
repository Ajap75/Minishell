/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anastruc <anastruc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 12:41:52 by anastruc          #+#    #+#             */
/*   Updated: 2024/07/03 12:55:31 by anastruc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_realloc(void *ptr, int size)
{
	void *new_memory_area;

	new_memory_area = malloc (sizeof (void *ptr) * size + 1);
	ft_strlcpy(new_memory_area, ptr, ft_strlen(ptr));

	return(new_memory_area);
}