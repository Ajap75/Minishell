/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anastruc <anastruc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 15:45:51 by anastruc          #+#    #+#             */
/*   Updated: 2024/07/04 17:53:25 by anastruc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/minishell.h"

// CD with only a relative or an absolute path.
// Relative path : Path from where you are in the arborescence.
// Absolute path : Path from the root.

// CD sans argument ; Revient au repertoir HOME specifie dans l'ENV si pas de home dans l'env exit

int	ft_cd(t_cmd *cmd, t_data *minishell)
{
	char **dir_tab;
	int i;
	if (cmd->cmd_args[1] == NULL)
	{
		while (ft_strcmp(minishell->env->var_name, "HOME") != 0
			&& minishell->env)
			minishell->env = minishell->env->next;
		if (minishell->env == NULL)
			exit(err_msg(HOME_NOT_SET, cmd->cmd_name, cmd, minishell));
		else
		{
			// ft_putstr_fd (minishell->env->var_value, 2);
			dir_tab = ft_split(cmd->cmd_args[0], '/');
			i = 0;
			ft_putstr_fd (dir_tab[i], 2);
			while (dir_tab[i])
			{
				if (ft_strcmp(dir_tab[i], ".") == 0)
					continue ;
				else
				{
						ft_putstr_fd ("HOUURA", 2);
					if (chdir(dir_tab[i]) == -1)
					{
						free(dir_tab);
						exit(err_msg(HOME_NOT_SET, cmd->cmd_name, cmd, minishell));
					}
				}
				i++;
			}
		}
	}
	dir_tab = ft_split(cmd->cmd_args[1], '/');
	i = 0;
	while (dir_tab[i])
	{
		if (ft_strcmp(dir_tab[i], ".") == 0)
			continue ;
		else
		{
			if (chdir(dir_tab[i]) == -1)
			{
				free(dir_tab);
				exit(err_msg(HOME_NOT_SET, cmd->cmd_name, cmd, minishell));
			}
		}
		i++;
	}
	free(dir_tab);
	return (0);
}