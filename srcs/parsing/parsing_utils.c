/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsalomon <fsalomon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 14:36:39 by fsalomon          #+#    #+#             */
/*   Updated: 2024/07/03 14:36:48 by fsalomon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/minishell.h"
#include "../../headers/parsing.h"

bool	is_separator_char(char c)
{
	if (c == '<' || c == '>' || ft_isspace(c) || c == '|' || c == '"'
		|| c == 39)
		return (true);
	else
		return (false);
}

bool	is_there_a_sis_quote(char *input_start)
{
	int	i;

	i = 0;
	while (input_start[i])
	{
		if (input_start[i] == '"')
			return (true);
		i++;
	}
	return (false);
}