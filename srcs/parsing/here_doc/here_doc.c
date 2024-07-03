/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsalomon <fsalomon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 16:48:16 by fsalomon          #+#    #+#             */
/*   Updated: 2024/07/03 16:48:58 by fsalomon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../headers/minishell.h"
#include "../../../headers/parsing.h"

static void	add_line_to_file(char *line, int fd)
{
	ft_putstr_fd(line, fd);
}

static void	read_input_heredoc(int fd, char *delimiter, char *file_name,
		t_data *minishell)
{
	char	*line;
	int		i;

	i = 0;
	line = readline("> ");
	if (line == NULL)
	{
		stop_here_doc(delimiter, i);
		unlink(file_name);
	}
	while (line && !is_it_delimiter(line, delimiter))
	{
		i++;
		line = change_expand(line, minishell);
		add_line_to_file(line, fd);
		add_line_to_file("\n", fd);
		free(line);
		line = readline("> ");
		if (line == NULL)
		{
			stop_here_doc(delimiter, i);
			unlink(file_name);
			break ;
		}
	}
	free(line);
	free(delimiter);
	close(fd);
	return ;
}

static char	*handle_here_doc(char *input, int num_handle, t_data *minishell)
{
	t_redir_file	*here_doc;
	int				fd_heredoc;
	char			*delimiter;

	here_doc = ft_calloc(sizeof(t_redir_file), 1);
	fd_heredoc = create_heredoc_file(here_doc);
	delimiter = get_delimiter(input, num_handle);
	if (!delimiter)
	{
		free(input);
		free(here_doc->file_name);
		free(here_doc);
		close(fd_heredoc);
		malloc_error(minishell);
	}
	input = put_file_name(input, here_doc->file_name, delimiter);
	if (!input)
	{
		free(delimiter);
		free(here_doc->file_name);
		free(here_doc);
		close(fd_heredoc);
		malloc_error(minishell);
	}
	read_input_heredoc(fd_heredoc, delimiter, here_doc->file_name, minishell);
	lst_redir_file_clear(here_doc);
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

char	*process_heredocs(char *input, t_data *minishell)
{
	int	num_heredoc;
	int	i;
	int	num_handle;

	i = 0;
	num_handle = 0;
	num_heredoc = how_many_heredoc(input);
	while (i < num_heredoc)
	{
		input = handle_here_doc(input, num_handle, minishell);
		i++;
		num_handle++;
	}
	return (input);
}
