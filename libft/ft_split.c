/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsalomon <fsalomon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 15:39:35 by fsalomon          #+#    #+#             */
/*   Updated: 2023/11/21 11:41:06 by fsalomon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_words(int i, char *str, char c)
{
	int	words;

	words = 0;
	while (str[i] != 0)
	{
		while (str[i] == c && str[i])
		{
			i++;
		}
		if (str[i] != 0)
			words++;
		while (str[i] != c && str[i])
			i++;
	}
	return (words);
}

static int	count_len(int i, char *str, char c)
{
	int	len;

	len = 0;
	while (str[i] != 0)
	{
		while (str[i] != c && str[i])
		{
			i++;
			len++;
		}
		return (len);
	}
	return (len);
}

static char	**malloc_strings(char **splitted, char *str, char c)
{
	int	i;
	int	n;

	i = 0;
	n = 0;
	while (str[i] != 0)
	{
		if (str[i] != c)
		{
			splitted[n] = malloc(sizeof(char) * count_len(i, str, c) + 1);
			if (!splitted[n])
			{
				while (n >= 0)
					free(splitted[n--]);
				free(splitted);
				return (NULL);
			}
			n ++;
			i = i + (count_len(i, str, c)) - 1;
		}
		i ++;
	}
	return (splitted);
}

static char	**ft_split_it(char *s, char **splitted, char c)
{
	int	i;
	int	j;
	int	n;

	i = 0;
	j = 0;
	n = 0;
	while (s[i] != 0)
	{
		j = 0;
		while (s[i] != c && s[i])
			splitted[n][j++] = s[i++];
		while (s[i] == c && s[i])
			i++;
		if (j != 0)
		{
			splitted[n][j] = 0;
			n++;
		}
	}
	splitted[n] = 0;
	return (splitted);
}

char	**ft_split(char const *s, char c)
{
	char	**splitted;
	int		i;

	i = 0;
	if (!s)
		return (NULL);
	splitted = NULL;
	splitted = malloc(sizeof(char *) * (count_words(i, (char *)s, c) + 1));
	if (!splitted)
		return (NULL);
	splitted = malloc_strings(splitted, (char *)s, c);
	if (splitted == NULL)
		return (NULL);
	splitted = ft_split_it((char *)s, splitted, c);
	return (splitted);
}

/* int	main(void)
{
	char	**tab;
	int		i;

	tab = ft_split("deidjie/dejdie/2233/deded/o", '/');
	i = 0;
	while (tab[i] != 0)
	{
		printf("%s \n", tab[i]);
		i++;
	}
	return (0);
} */