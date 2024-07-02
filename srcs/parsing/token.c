/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsalomon <fsalomon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 17:15:22 by fsalomon          #+#    #+#             */
/*   Updated: 2024/07/02 16:20:12 by fsalomon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/minishell.h"
#include "../../headers/parsing.h"

// bool	is_redir(char *line, int *index)
// {
// 	char	redir;
// 	char	redir_2;

// 	redir = line[*index];
// 	if (redir == '<' || redir == '>')
// 	{
// 		if (redir == '<')
// 			redir_2 = '>';
// 		else
// 			redir_2 = '<';
// 		if (line[*index + 1] == redir)
// 		{
// 			if (line[*index + 2] == '>' || line[*index + 2] == '<')
// 			{
// 				error_parsing(SYNTAX_ERROR, &line[*index + 2]);
// 				free(line);
// 				exit(EXIT_FAILURE);
// 			}
// 			else
// 			{
// 				*index += 2;
// 				return (true);
// 			}
// 		}
// 		else if (line[*index + 1] == redir_2)
// 		{
// 			error_parsing(SYNTAX_ERROR, &line[*index + 2]);
// 			free(line);
// 			exit(EXIT_FAILURE);
// 		}
// 		else
// 		{
// 			*index += 1;
// 			return (true);
// 		}
// 	}
// 	return (false);
// }


// bool	is_normal_char(char *line, int *index)
// {
// 	while (line[*index] != '<' || line[*index] != '>' || line[*index] != '|' ||!ft_isspace(line[*index]))
// 		*index++;
// }

// bool	is_pipe(char *line, int *index)
// {
// 	char	c;

// 	c = line[*index];
// 	if (c == "|")
// 	{
// 		if (line[*index + 1] == c)
// 		{
// 			error_parsing(SYNTAX_ERROR, c);
// 			free(line);
// 			exit(EXIT_FAILURE);
// 		}
// 		else
// 		{
// 			*index += 1;
// 			return (true);
// 		}
// 	}
// 	else
// 		return (false);
// }

// char	*split_input(char *line, int *i)
// {
// 	char	*token;

// 	token = NULL;
// 	if (is_redir(line, i))
// 		token = strlcpy(line, sizeof(&line[*i] - &line));
// 	else if (is_pipe(line, i))
// 		token = strlcpy(line, sizeof(&line[*i] - &line));
// 	else if (is_quote(line, i))
// 		token = handle_quote(line, i);
// 	else if (is_normal_char(line, i))
// 		token = strlcpy(line, sizeof(&line[*i] - &line));
// 	if (token)
// 		return (token);
// 	else
// 		return (NULL);
// }
