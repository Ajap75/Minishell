/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anastruc <anastruc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 11:19:18 by fsalomon          #+#    #+#             */
/*   Updated: 2024/07/04 12:25:49 by anastruc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

int	main(int argc, char **argv, char *envp[])
{
	// (void)argc;
	(void)argv;
	(void)argc;

	t_data	*minishell;

	minishell = NULL;
	minishell = ft_init_data(envp, minishell);
	init_data_for_test_antoine(minishell);
	return(execution(minishell));
}
void	init_data_for_test_antoine(t_data *minishell)
{

	t_cmd	*cursor;
	minishell->cmd_list = lst_cmd_new_node();
	minishell->cmd_list->cmd_pos = FIRST_CMD;
	minishell->cmd_list->cmd_type = CMD;
	minishell->cmd_list->cmd_args = malloc(sizeof(char *) * 2);
	minishell->cmd_list->cmd_args[0] = malloc(sizeof(char)* (ft_strlen("ls") + 1));
	minishell->cmd_list->cmd_name = malloc(sizeof(char)* (ft_strlen("ls") + 1));
	strcpy(minishell->cmd_list->cmd_name, "ls");
	strcpy(minishell->cmd_list->cmd_args[0], "ls");
	minishell->cmd_list->cmd_args[1] = NULL;
	minishell->cmd_list->file_in = init_node_lst_file(SRC_REDIR, "infile1");
	lst_redir_file_addback(&minishell->cmd_list->file_in, init_node_lst_file(SRC_REDIR, "infile2"));
	lst_redir_file_addback(&minishell->cmd_list->file_in, init_node_lst_file(SRC_REDIR, "infile3"));
	cursor = lst_cmd_new_node();
	cursor->cmd_pos = BETWEEN_CMD;
	cursor->cmd_name = malloc(sizeof(char)* (ft_strlen("cat") + 1));
	strcpy(cursor->cmd_name, "cat");
	cursor->cmd_type = CMD;
	cursor->cmd_args = malloc(sizeof(char *) * 2);
	cursor->cmd_args[0] = malloc(sizeof(char)* (ft_strlen("cat") + 1));
	strcpy(cursor->cmd_args[0], "c8t");
	// cursor->cmd_args[1] = malloc(sizeof(char)* (ft_strlen("-z") + 1));
	// strcpy(cursor->cmd_args[0], "-z");
	cursor->cmd_args[1] = NULL;
	lst_cmd_addback(&(minishell->cmd_list), cursor);
	cursor = lst_cmd_new_node();
	cursor->cmd_pos = LAST_CMD;
	cursor->cmd_type = CMD;
	cursor->cmd_name = malloc(sizeof(char)* (ft_strlen("cat") + 1));
	strcpy(cursor->cmd_name, "cat");
	cursor->cmd_args = malloc(sizeof(char *) * 2);
	cursor->cmd_args[0] = malloc(sizeof(char)* (ft_strlen("cat") + 1));
	strcpy(cursor->cmd_args[0], "cat");
	cursor->cmd_args[1] = NULL;
	cursor->file_out = init_node_lst_file(DST_REDIR, "outfile1");
	lst_redir_file_addback(&cursor->file_out, init_node_lst_file(DST_REDIR, "outfile2"));
	lst_redir_file_addback(&cursor->file_out, init_node_lst_file(APPEND, "outfile3"));
	lst_cmd_addback(&(minishell->cmd_list), cursor);
}

// int	main(void)
// {
// 	t_data	*minishell;

// t_data data_to_exec;
// data_to_exec = ft_init_data(envp);
// exec(data_to_exec);
// minishell = NULL;
// 	ft_init_data(envp);
// 	minishell = get_data();
// 	print_env_lst(minishell->env);
// 	printf("ENVP : \n%s\n", minishell->env->var_name);
// 	lst_env_clear(minishell->env);
// 	free(command_line);
// 	return (0);
// }

// int	main(int argc, char **argv, char *envp[])
// {
// 	char	*input;

// 	(void)argv;
// 	(void)argc;
// 	(void)envp;
// r1_bind_key('\t', r1_complete); //
// 	while (1)
// 	{
// 		listen_signal();
// 		input = readline("bash-5.1$ ");
// 		if (input == NULL)
// 		{
// 			printf("exit\n");
// 			exit(EXIT_FAILURE);
// 		}
// 		if (*input)
// 			add_history(input);
// 	}
// 	return (1);
// }

// }

// int	run_minishell(char *command_line, char *envp[])
// {
// t_data data_to_exec;
// data_to_exec = ft_init_data(envp);
// exec(data_to_exec);
//}

// 	t_data	*minishell;
// minishell = NULL;

// 	ft_init_data(envp);
// 	minishell = get_data ();
// 	print_env_lst(minishell->env);
// 	printf("ENVP : \n%s\n", minishell->env->var_name);
// 	lst_env_clear(minishell->env);
// 	free(command_line);
// 	return(0);
// }

// int	main(int argc, char **argv, char *envp[])
// {
// 	char	*input;
// 	(void) argv;
// 	(void) argc;
	// r1_bind_key('\t', r1_complete); //
// 	while (1)
// 	{
// 		input = readline("Minishell > ");
// 		if (input == NULL)
// 		{
// 			printf("Doit quitter le prog ex ctrl_D\n");
// 			exit(EXIT_FAILURE);
// 		}
// 		if (*input)
// 		{
// 			add_history(input);
// 			return (run_minishell(input, envp));
// 		}
// 	}
// 	return (1);
// }
