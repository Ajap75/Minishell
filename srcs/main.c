/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsalomon <fsalomon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 11:19:18 by fsalomon          #+#    #+#             */
/*   Updated: 2024/06/29 15:14:26 by fsalomon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

int	run_minishell(char *command_line, char *envp[])
{
	// t_data data_to_exec;
	// data_to_exec = ft_init_data(envp);
	// exec(data_to_exec);


	t_data	*minishell;
	// minishell = NULL;

	ft_init_data(envp);
	minishell = get_data ();
	print_env_lst(minishell->env);
	printf("ENVP : \n%s\n", minishell->env->var_name);
	lst_env_clear(minishell->env);
	free(command_line);
	return(0);
}

int	main(int argc, char **argv, char *envp[])
{
	char	*input;
	(void) argv;
	(void) argc;
	(void) envp;
	// r1_bind_key('\t', r1_complete); //
	while (1)
	{
		input = readline("bash-5.1$ ");
		if (input == NULL)
		{
			printf("exit\n");
			exit(EXIT_FAILURE);
		}
		listen_signal();
		if (*input)
		{
			add_history(input);
		}
	}
	return (1);
}
