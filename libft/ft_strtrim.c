/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsalomon <fsalomon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 12:00:22 by fsalomon          #+#    #+#             */
/*   Updated: 2023/11/11 15:48:49 by fsalomon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_is_set(char c, char const *set)
{
	int	i;

	i = 0;
	while (set[i] != 0)
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

static int	ft_count_set(char const *s1, char const *set)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (ft_is_set(s1[i], set))
	{
		i++;
		count++;
	}
	return (count);
}

static int	ft_end_index(char const *s1, char const *set)
{
	size_t	s1_len;
	size_t	i;
	int		end_index;

	i = 0;
	s1_len = ft_strlen(s1) - 1;
	while (ft_is_set(s1[s1_len - i], set))
	{
		i++;
	}
	end_index = s1_len - i + 1;
	return (end_index);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		num_set_beg;
	int		i;
	int		num_cpy;
	char	*new_string;

	i = 0;
	if (!s1)
		return (NULL);
	num_set_beg = ft_count_set(s1, set);
	if ((int)ft_strlen(s1) > num_set_beg)
		num_cpy = ((ft_end_index(s1, set) - num_set_beg));
	else
		num_cpy = 0;
	new_string = malloc(sizeof(char) * num_cpy + 1);
	if (!new_string)
		return (NULL);
	while (i < num_cpy)
	{
		new_string[i] = s1[i + num_set_beg];
		i++;
	}
	new_string[i] = 0;
	return (new_string);
}

/* #include <unistd.h>

void	ft_print_result(char const *s)
{
	int	len;

	len = 0;
	while (s[len])
		len++;
	write(1, s, len);
}

int	main(void)
{
	char	*strtrim;
	char	s1[] = "  \t \t \n   \n\n\n\t";


	if (!(strtrim = ft_strtrim(s1, " \n\t")))
			ft_print_result("NULL");
	else
		ft_print_result(strtrim);
	if (strtrim == s1)
		ft_print_result("\nA new string was not returned");
	return (0);
} */
