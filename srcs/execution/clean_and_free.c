/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_and_free.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anastruc <anastruc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 14:29:56 by anastruc          #+#    #+#             */
/*   Updated: 2024/07/04 13:13:11 by anastruc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/minishell.h"

void	close_fd(t_cmd *cmd)
{
	// if (cmd->cmd_pos != ONLY_ONE_CMD && cmd->cmd_pos != LAST_CMD)
	// 	cmd->next->last_pipe_read_end = cmd->pipe[0];
	if (cmd->pipe[0] != -1)
		close(cmd->pipe[0]);
	if (cmd->pipe[1] != -1)
		close(cmd->pipe[1]);
	if (cmd->last_pipe_read_end != -1)
		close(cmd->last_pipe_read_end);
	if (cmd->infilefd != -1)
		close(cmd->infilefd);
	if (cmd->outfilefd != -1)
		close(cmd->infilefd);
}


int	err_msg(int err_type, char *elmt, t_cmd *cmd, t_data *minishell)
{
	if (cmd)
		close_fd(cmd);
	if (err_type == NO_SUCH_FILE)
	{
		ft_putstr_fd("bash: ", 2);
		ft_putstr_fd(elmt, 2);
		ft_putstr_fd(": No such file or directory\n", 2);
		clean_all(minishell);
		return (1);
	}
	if (err_type == CMD_NOT_EXECUTABLE)
	{
		ft_putstr_fd("bash: ", 2);
		ft_putstr_fd(elmt, 2);
		ft_putstr_fd(": command not found\n", 2);
		clean_all(minishell);
		return (126);
	}
	else if (err_type == CMD_NOT_FOUND)
	{
		ft_putstr_fd("bash: ", 2);
		ft_putstr_fd(elmt, 2);
		ft_putstr_fd(": Permission denied\n", 2);
		clean_all(minishell);
		return (127);
	}
	else if (err_type == PERMISSION_DENIED)
	{
		ft_putstr_fd("bash: ", 2);
		ft_putstr_fd(elmt, 2);
		ft_putstr_fd(": Permission denied\n", 2);
		clean_all(minishell);
		return (1);
	}
	else if (err_type == DUP2_FAIL)
	{
		ft_putstr_fd("bash: ", 2);
		ft_putstr_fd(elmt, 2);
		ft_putstr_fd(": DUP2 FAIL\n", 2);
		clean_all(minishell);
		return (1);
	}
	else if (err_type == OPEN_FAIL)
	{
		ft_putstr_fd("bash: ", 2);
		ft_putstr_fd(elmt, 2);
		ft_putstr_fd(": OPEN FAIL\n", 2);
		clean_all(minishell);
		return (1);
	}


	return (0);
}