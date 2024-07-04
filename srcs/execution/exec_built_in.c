/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_built_in.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anastruc <anastruc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 16:48:10 by anastruc          #+#    #+#             */
/*   Updated: 2024/07/04 17:32:56 by anastruc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/minishell.h"

void	exec_built_in(t_cmd *cmd, t_data *minishell)
{
	// if (cmd->cmd_name == "echo")
	// 	ft_echo()
	if (ft_strcmp(cmd->cmd_name, "cd") == 0)
		ft_cd(cmd, minishell);
	// else if (cmd->cmd_name == "pwd")
	// 	ft_pwd()
	// else if (cmd->cmd_name == "export")
	// 	ft_export()
	// else if (cmd->cmd_name == "unset")
	// 	ft_unset()
	// else if (cmd->cmd_name == "env")
	// 	ft_env()
	// else if (cmd->cmd_name == "exit")
	// 	ft_exit()
}
