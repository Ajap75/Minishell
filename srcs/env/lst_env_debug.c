/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_env_debug.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anastruc <anastruc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 16:15:53 by anastruc          #+#    #+#             */
/*   Updated: 2024/06/27 16:28:19 by anastruc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/minishell.h"

void	print_env_node(t_env *node)
{
	printf("Var_name : %s\n", node->var_name);
	printf("Var_value : %s\n\n", node->var_value);
}

void	print_env_lst(t_env *node)
{
	t_env	*tmp;

	tmp = node;
	while (tmp)
	{
		print_env_node(tmp);
		tmp = tmp->next;
	}
}

// int	main(int argc, char **argv, char *envp[])
// {
// 	t_env	*lst_env;
// 	(void)argv;
// 	// envp[0] = NULL;
// 	if (argc >= 1)
// 	{
// 		lst_env = get_env(envp);
// 		print_env_lst(lst_env);
// 		lst_env_clear(lst_env);
// 	}
// 	return (0);
// }
