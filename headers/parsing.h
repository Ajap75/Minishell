/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsalomon <fsalomon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 16:48:58 by fsalomon          #+#    #+#             */
/*   Updated: 2024/07/02 16:15:03 by fsalomon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include "minishell.h"
# include <sys/time.h>
# include <time.h>

# define HERE_STRING_ERROR 2048
# define SYNTAX_ERROR 4096

// here_doc

void	process_heredocs(char *input);
bool	is_it_delimiter(char *line, char *del);
char	*get_delimiter(char *input, int num_handle);
char	*put_file_name(char *input, char *file_name, char *delimiter);
int		create_heredoc_file(t_redir_file *here_doc);
char	*change_expand(char *line);
bool	there_is_expand(char *line);

#endif

// parsing
bool	is_separator_char(char c);
void	do_parsing(t_data *minishell, char **tokens, char *input);
void	error_parsing(int flag, char *token);