/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anastruc <anastruc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 11:19:18 by fsalomon          #+#    #+#             */
/*   Updated: 2024/06/28 10:44:09 by anastruc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

int	main(int argc, char **argv, char *envp[])
{
	char	*input;

	// r1_bind_key('\t', r1_complete); //
	while (1)
	{
		input = readline("Minishell > ");
		if (input == NULL)
		{
			printf("Doit quitter le prog ex ctrl_D\n");
			break ;
		}
		if (*input)
		{
			add_history(input);
			return (run_minishell(input, envp));
		}
	}
	return (1);
}

int	run_minishell(char *command_line, char *envp[])
{
	// t_data data_to_exec;
	// data_to_exec = ft_init_data(envp);
	// exec(data_to_exec);
	t_data	*minishell;
	minishell = malloc(sizeof(t_data));
	minishell = ft_init_data(envp);
	printf("ENVP : \n%s\n", minishell->env->var_name);
}