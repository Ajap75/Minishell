/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsalomon <fsalomon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 18:15:08 by fsalomon          #+#    #+#             */
/*   Updated: 2023/11/14 15:24:50 by fsalomon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*substring;
	size_t	substring_len;
	size_t	j;

	i = 0;
	substring_len = 0;
	if (!s)
		return (0);
	i = ft_strlen(s);
	while (substring_len < len && start <= i && s[substring_len + start])
		substring_len++;
	substring = malloc((substring_len * sizeof(char)) + 1);
	if (!substring)
		return (NULL);
	j = 0;
	while (j < substring_len)
	{
		substring[j] = s[start + j];
		j++;
	}
	substring[j] = 0;
	return (substring);
}
/* 
int	main(void)
{
	char	*test;
	char	*test2;

	test = strdup("1");
	printf("%p \n", test);
	test2 = ft_substr(test, 42, 42000000);
	printf("%p \n", test2);
	free(test);
	free(test2);
	return (0);
} */
