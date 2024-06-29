/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc_utils2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsalomon <fsalomon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 17:13:48 by fsalomon          #+#    #+#             */
/*   Updated: 2024/06/29 17:14:47 by fsalomon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/minishell.h"
#include "../../headers/parsing.h"

void	add_line_to_file(char *line, int fd)
{
	ft_putstr_fd(line, fd);
}

char	*change_expand(char *line)
{
	if (there_is_expand(line))
	{
		// chemin pour faire lex expands ??
	}
	return (line);
}
