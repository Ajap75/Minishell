/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsalomon <fsalomon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 17:17:48 by fsalomon          #+#    #+#             */
/*   Updated: 2024/06/29 17:18:30 by fsalomon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/minishell.h"
#include "../../headers/parsing.h"

char	**tokenise_input(char *input)
{
	char	**tokens;
	int		t;
	int		i;
	int		input_len;

	t = 0;
	i = 0;
	input_len = ft_strlen(input);
	while (i < input_len)
	{
		while (input[i] == " ")
			i++;
		tokens[t] = split_input(&input[i], &i);
		if (tokens[t])
			t++;
	}
	tokens[t] = NULL;
}

void	do_parsing(t_data *minishell, char **tokens, char *input)
{
	if (is_there_here_doc(input))
		process_heredocs(input);
	tokens = tokenize_input(input);
	handle_expand(tokens);
	init_cmd_list(tokens);
	ft_free_split(tokens);
	init_cmd_pos(minishell->cmd_list);
}
