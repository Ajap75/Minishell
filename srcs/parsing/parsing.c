/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsalomon <fsalomon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 17:17:48 by fsalomon          #+#    #+#             */
/*   Updated: 2024/07/03 16:53:13 by fsalomon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/minishell.h"
#include "../../headers/parsing.h"


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

static bool	is_there_here_doc(char *input, t_data *minishell)
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
				error_parsing(HERE_STRING_ERROR, NULL,minishell);
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

static char	*trim_quote_alone(char *input)
{
	char	*new_input;
	int		i;
	int		sis_flag;

	i = 0;
	sis_flag = 0;
	new_input = ft_calloc(sizeof(char) , (ft_strlen(input) + 1));
	while (input[i])
	{
		if (input[i] == '"' && !sis_flag)
		{
			sis_flag = is_there_a_sis_quote(&input[i + 1]);
			if (!sis_flag)
				new_input[i] = 32;
			else
				new_input[i] = input[i];
		}
		else
			new_input[i] = input[i];
		i++;
	}
	new_input[i] = 0;
	free(input);
	return (new_input);
}

void	do_parsing(t_data *minishell, char **tokens, char *input)
{
	(void)tokens;
	input = trim_quote_alone(input);
	if (is_there_here_doc(input, minishell))
		input = process_heredocs(input, minishell);
	(void)minishell;
	free(input);
	// tokens = tokenize_input(input);
	// handle_expand(tokens);
	// init_cmd_list(tokens);
	// ft_free_split(tokens);
	// init_cmd_pos(minishell->cmd_list);
}
