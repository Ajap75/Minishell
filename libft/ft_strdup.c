/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsalomon <fsalomon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 18:43:03 by fsalomon          #+#    #+#             */
/*   Updated: 2024/04/13 16:37:21 by fsalomon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*new_string;
	int		string_len;
	int		i;

	string_len = ft_strlen(s);
	if (string_len == 2147483647)
		return (NULL);
	new_string = malloc(sizeof(char) * (string_len + 1));
	if (!new_string)
		return (NULL);
	i = 0;
	while (i < string_len)
	{
		new_string[i] = ((char *)s)[i];
		i++;
	}
	new_string[i] = 0;
	return (new_string);
}

/*
#include <unistd.h>

void	ft_print_result(char const *s)
{
	int		len;

	len = 0;
	while (s[len])
		len++;
	write(1, s, len);
}

int		main(int argc, const char *argv[])
{
	char	str[] = "lorem ipsum dolor sit amet";
	char	*str_dup;

	alarm(5);
	if (argc == 1)
		return (0);
	if (atoi(argv[1]) == 1)
	{
		if (!(str_dup = ft_strdup(str)))
			ft_print_result("NULL");
		else
			ft_print_result(str_dup);
		if (str_dup == str)
			ft_print_result("\nstr_dup's adress == str's adress");
	}
	return (0);
}*/