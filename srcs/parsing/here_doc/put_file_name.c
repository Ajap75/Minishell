/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_file_name.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsalomon <fsalomon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 12:00:15 by fsalomon          #+#    #+#             */
/*   Updated: 2024/07/03 15:33:36 by fsalomon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../headers/minishell.h"
#include "../../../headers/parsing.h"

static char	*allocate_new_input(char *input, char *file_name, char *delimiter)
{
	int		new_input_len;
	char	*new_input;

	new_input_len = ft_strlen(input) + ((ft_strlen(file_name)
				- (ft_strlen(delimiter))));
	new_input = ft_calloc(sizeof(char), (new_input_len + 1));
	return (new_input);
}

static int	copy_first_part_input(char *new_input, char *input, int i,
		char *del)
{
	int		input_len;
	char	*del_start;

	input_len = ft_strlen(input);
	del_start = ft_strnstr(input, del, input_len);
	while (&input[i] != del_start)
	{
		new_input[i] = input[i];
		i++;
	}
	return (i);
}

static int	copy_file_name_input(char *new_input, char *file_name, int i)
{
	int	d;

	d = 0;
	while (file_name[d] != 0)
	{
		new_input[i + d] = file_name[d];
		d++;
	}
	return (i + d);
}

char	*put_file_name(char *input, char *file_name, char *delimiter)
{
	int		i;
	int		j;
	char	*new_input;

	i = 0;
	new_input = allocate_new_input(input, file_name, delimiter);
	if (!new_input)
		return (free(input), NULL);
	i = copy_first_part_input(new_input, input, i, delimiter);
	j = copy_file_name_input(new_input, file_name, i);
	i += ft_strlen(delimiter);
	while (input[i] != 0)
	{
		new_input[j] = input[i];
		j++;
		i++;
	}
	free(input);
	return (new_input);
}
