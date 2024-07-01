/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anastruc <anastruc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 14:16:05 by anastruc          #+#    #+#             */
/*   Updated: 2024/07/01 14:12:16 by anastruc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/minishell.h"

exec(t_cmd *cmd)
{
	t_data *minishell;

	minishell = get_data();
	if (cmd->cmd_type == CMD)
	{
		find_cmd_path(cmd);
		if (ft_strchr(cmd->cmd_name, '/'))
			cmd->cmd_path = cmd->cmd_name;
		else if (cmd->cmd_path == NULL)
			exit(err_msg(CMD_NOT_FOUND));
		else
			execve(cmd->cmd_path, cmd->cmd_args, minishell->envp);
	}
	// else if (cmd->cmd_type == BUILT_IN)
}


void	find_cmd_path (t_cmd *cmd)
{
	t_env *tmp;
	char **possible_path_tab;
	int	i;
	char *back_slash_possible_path_tab;

	i = 0;
	if (tmp)
	{
		while (tmp->var_name != "PATH")
			tmp = tmp->next;
	}
	possible_path_tab = ft_split(tmp->var_value, ':');
	while (possible_path_tab[i])
	{
		back_slash_possible_path_tab = ft_strjoin('/', possible_path_tab[i]);
		if (access(back_slash_possible_path_tab, F_OK | X_OK) == 0)
		{
			cmd->cmd_path = back_slash_possible_path_tab;
			break;
		}
		free(back_slash_possible_path_tab);
		i++;
	}
	ft_free_split(possible_path_tab);
}


