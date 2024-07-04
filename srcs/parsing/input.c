/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anastruc <anastruc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 16:46:30 by fsalomon          #+#    #+#             */
/*   Updated: 2024/07/03 17:41:05 by anastruc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/minishell.h"
#include "../../headers/parsing.h"

static bool	is_this_empty_line(char *input)
{
	int	i;

	i = 0;
	while (input[i])
	{
		if (!ft_isspace(input[i]))
			return (false);
		i++;
	}
	return (true);
}

static char	*get_input(t_data *minishell)
{
	char	*prompt;
	char	*input;

	prompt = "bash-5.1$ ";
	input = readline(prompt);
	if (input == NULL)
	{
		ft_putstr_fd("exit\n", STDOUT_FILENO);
		clean_all(minishell);
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

	tokens = NULL;
	input = NULL;
	while (1)
	{
		input = get_input(minishell);
		if (!is_this_empty_line(input))
			do_parsing(minishell, tokens, input);
		else
			free(input);
	}
}
// int	main(int argc, char **argv, char *envp[])
// {
// 	(void)argc;
// 	(void)argv;
// 	t_data *minishell;

// 	ft_init_data(envp);
// 	minishell = get_data();
// 	parse_input(minishell);

// }
