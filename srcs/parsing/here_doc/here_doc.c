/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsalomon <fsalomon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 16:48:16 by fsalomon          #+#    #+#             */
/*   Updated: 2024/07/02 17:47:55 by fsalomon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../headers/minishell.h"
#include "../../../headers/parsing.h"

static void	add_line_to_file(char *line, int fd)
{
	ft_putstr_fd(line, fd);
}

static void	read_input_heredoc(int fd, char *delimiter)
{
	char	*line;

	line = readline(">");
	while (!is_it_delimiter(line, delimiter))
	{
		line = change_expand(line);
		add_line_to_file(line, fd);
		add_line_to_file("\n", fd);
		free(line);
		line = readline(">");
	}
	free(line);
	free(delimiter);
	printf("JE CLOSE\n");
	close(fd);
	return ;
}

static char	*handle_here_doc(char *input, int num_handle)
{
	t_redir_file	*here_doc;
	int				fd_heredoc;
	char			*delimiter;

	here_doc = malloc(sizeof(t_redir_file));
	fd_heredoc = create_heredoc_file(here_doc);
	delimiter = get_delimiter(input, num_handle);
	if (!delimiter)
	{
		free(input);
		free(here_doc->file_name);
		free(here_doc);
		close(fd_heredoc);
		malloc_error();
	}
	input = put_file_name(input, here_doc->file_name, delimiter);
	if (!input)
	{
		free(delimiter);
		free(here_doc->file_name);
		free(here_doc);
		close(fd_heredoc);
		malloc_error();
	}
	read_input_heredoc(fd_heredoc, delimiter);
	return (input);
}

static int	how_many_heredoc(char *input)
{
	int	num_heredoc;
	int	i;

	num_heredoc = 0;
	i = 0;
	while (input[i])
	{
		if (input[i] == '<' && input[i + 1] == '<')
			num_heredoc++;
		i++;
	}
	return (num_heredoc);
}

void	process_heredocs(char *input)
{
	int	num_heredoc;
	int	i;
	int	num_handle;

	i = 0;
	num_handle = 0;
	num_heredoc = how_many_heredoc(input);
	while (i < num_heredoc)
	{
		input = handle_here_doc(input, num_handle);
		i++;
		num_handle++;
	}
}
