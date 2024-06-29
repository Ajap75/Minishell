/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsalomon <fsalomon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 16:46:30 by fsalomon          #+#    #+#             */
/*   Updated: 2024/06/29 17:18:15 by fsalomon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/minishell.h"
#include "../../headers/parsing.h"


bool	is_this_empty_line(char *input)
{
	int	i;

	i = 0;
	while (input[i])
	{
		if (input[i] != " ")
			return (false);
		i++;
	}
	return (true);
}

char	*get_input(t_data *data)
{
	char	*prompt;
	char	*input;

	prompt = "bash-5.1$ ";
	input = readline(prompt);
	if (input == NULL)
	{
		ft_putstr_fd("exit\n", STDOUT_FILENO);
		exit(EXIT_FAILURE);
	}
	if (*input)
		add_history(input);
	return (input);
}

void	parse_input(t_data *minishell)
{
	char	**tokens;
	char	*input;

	while (1)
	{
		input = get_input(minishell);
		if (!this_is_empty_line(input))
			do_parsing(minishell, input, tokens);
		else
			free(input);
	}
}
