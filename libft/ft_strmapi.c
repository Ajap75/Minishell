/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsalomon <fsalomon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 14:05:50 by fsalomon          #+#    #+#             */
/*   Updated: 2023/11/14 14:14:37 by fsalomon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*new_string;
	int		i;

	i = 0;
	if (!s || !f)
		return (NULL);
	new_string = malloc(sizeof(char) * ft_strlen(s) + 1);
	if (!new_string)
		return (NULL);
	while (s[i] != 0)
	{
		new_string[i] = f(i, s[i]);
		i ++;
	}
	new_string[i] = 0;
	return (new_string);
}
