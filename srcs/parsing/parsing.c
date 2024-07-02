/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsalomon <fsalomon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 17:17:48 by fsalomon          #+#    #+#             */
/*   Updated: 2024/07/02 17:44:27 by fsalomon         ###   ########.fr       */
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

// char	**tokenise_input(char *input)
// {
// 	char	**tokens;
// 	int		t;
// 	int		i;
// 	int		input_len;

// 	t = 0;
// 	i = 0;
// 	input_len = ft_strlen(input);
// 	while (i < input_len)
// 	{
// 		while (ft_isspace(input[i]))
// 			i++;
// 		tokens[t] = split_input(&input[i], &i);
// 		if (tokens[t])
// 			t++;
// 	}
// 	tokens[t] = NULL;
// }

void	error_parsing(int flag, char *token)
{
	if (flag == SYNTAX_ERROR)
	{
		ft_putstr_fd("error bash: syntax error near unexpected token '",
			STDOUT_FILENO);
		ft_putstr_fd(token, STDOUT_FILENO);
		ft_putstr_fd(" ' ", STDOUT_FILENO);
		clean_all();
		exit(2);
	}
	if (flag == HERE_STRING_ERROR)
	{
		ft_putstr_fd("error: This shell do not handle here_string",
			STDOUT_FILENO);
		clean_all();
		exit(2);
	}
}

static bool	is_there_here_doc(char *input)
{
	int	i;

	i = 0;
	while (input[i])
	{
		if (input[i] == '<' && input[i + 1] == '<')
		{
			if (input[i + 2] == '<')
			{
				free(input);
				error_parsing(HERE_STRING_ERROR, NULL);
			}
			else
			{
				i += 2;
				while (input[i] && ft_isspace(input[i]))
					i++;
				if (input[i])
					return (true);
			}
		}
			i++;
	}
		return (false);
}

void	do_parsing(t_data *minishell, char **tokens, char *input)
{
	(void)tokens;
	if (is_there_here_doc(input))
		process_heredocs(input);
	(void)minishell;
	// tokens = tokenize_input(input);
	// handle_expand(tokens);
	// init_cmd_list(tokens);
	// ft_free_split(tokens);
	// init_cmd_pos(minishell->cmd_list);
}
