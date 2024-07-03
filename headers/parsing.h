/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsalomon <fsalomon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 16:48:58 by fsalomon          #+#    #+#             */
/*   Updated: 2024/07/03 16:47:59 by fsalomon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include "minishell.h"
# include <sys/time.h>
# include <time.h>

# define HERE_STRING_ERROR 16384
# define SYNTAX_ERROR 32768
# define STOP_HERE_DOC 65536

// here_doc

char *	process_heredocs(char *input, t_data *minishell);
bool	is_it_delimiter(char *line, char *del);
char	*get_delimiter(char *input, int num_handle);
char	*put_file_name(char *input, char *file_name, char *delimiter);
int		create_heredoc_file(t_redir_file *here_doc);
char	*change_expand(char *line, t_data *minishell);
bool	there_is_expand(char *line);

#endif

// parsing utils
bool	is_there_a_sis_quote(char *input_start);
bool	is_separator_char(char c);

// parsing
void	do_parsing(t_data *minishell, char **tokens, char *input);

// error parsing
void	error_parsing(int flag, char *token, t_data *minishell);
void	stop_here_doc(char *delimiter, int i);