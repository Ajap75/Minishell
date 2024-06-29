/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsalomon <fsalomon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 16:48:16 by fsalomon          #+#    #+#             */
/*   Updated: 2024/06/29 16:57:43 by fsalomon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/minishell.h"
#include "../../headers/parsing.h"

void	read_input_heredoc(int fd, char *delimiter)
{
	char *line;
	
	line = readline(">");
	while (!it_is_delimiter(line, delimiter))
	{
		line = change_expand(line);
		add_line_to_file(line, fd);
		free(line);
		line = readline(">");
	}
	free(line);
	close(fd);
	return ;
}

char	*handle_here_doc(char *input)
{
	t_redir_file	*here_doc;
	int				fd_heredoc;
	char			*delimiter;

	fd_heredoc = create_heredoc_file(here_doc);
	delimiter = get_delimiter(input);
	input = put_file_name(input, here_doc);
	read_input_heredoc(fd_heredoc, delimiter);
	return (input);
}

int	how_many_heredoc(char *input)
{
	int	num_heredoc;
	int	i;

	num_heredoc = 0;
	i = 0;
	while (input[i])
	{
		if (input[i] == "<" && input[i + 1] == "<")
			num_heredoc++;
		i++;
	}
	return (num_heredoc);
}

void	process_heredocs(char *input)
{
	int	num_heredoc;
	int	i;

	i = 0;
	num_heredoc = how_many_heredoc(input);
	while (i < num_heredoc)
	{
		input = handle_here_doc(input);
		i++;
	}
}

bool	is_there_here_doc(char *input)
{
	int	i;

	i = 0;
	while (input[i])
	{
		if (input[i] == "<" && input[i + 1] == "<")
		{
			if (input[i + 2] == "<")
			{
				free(input);
				error_parsing(HERE_STRING_ERROR, NULL);
			}
			else
			{
				i += 2;
				while (input[i] && input[i] == " ")
					i++;
				if (input[i])
					return (true);
			}
			i++;
		}
		return (false);
	}
}
