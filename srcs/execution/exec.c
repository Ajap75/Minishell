/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anastruc <anastruc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 14:16:05 by anastruc          #+#    #+#             */
/*   Updated: 2024/07/04 12:55:29 by anastruc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/minishell.h"

int	execution(t_data *minishell)
{
	int		pid;
	t_cmd	*cmd;
	int		exit_status;

	exit_status = 0;
	cmd = minishell->cmd_list;
	while (cmd != NULL)
	{
		if (pipe(cmd->pipe) == -1)
			exit(EXIT_FAILURE);
		pid = fork();
		if (pid == -1)
			exit(EXIT_FAILURE);
		if (pid == 0)
			child_process(cmd, minishell);
		clean_parent_fd_and_set_last_pipe_read_end(cmd);
		cmd = cmd->next;
	}
	clean_all(minishell);
	wait_for_children_to_end(exit_status);
	return (exit_status);
}

void	child_process(t_cmd *cmd, t_data *minishell)
{
	pipe_redirection(cmd, minishell);
	operand_redirection(cmd, minishell);
	exec_cmd(cmd, minishell);
	close_fd(cmd);
	clean_all(minishell);
}

void	clean_parent_fd_and_set_last_pipe_read_end(t_cmd *cmd)
{
	if (cmd->next != NULL)
		cmd->next->last_pipe_read_end = cmd->pipe[0];
	close(cmd->pipe[1]);
	if (cmd->prev != NULL)
		close(cmd->prev->pipe[0]);
	if (cmd->next == NULL)
		close(cmd->pipe[0]);
}

void	exec_cmd(t_cmd *cmd, t_data *minishell)
{
	if (cmd->cmd_type == CMD)
	{
		find_cmd_path(cmd, minishell);
		if (ft_strchr(cmd->cmd_name, '/'))
			cmd->cmd_path = cmd->cmd_name;
		if (cmd->cmd_path == NULL)
			exit(err_msg(CMD_NOT_FOUND, cmd->cmd_name, cmd, minishell));
		ft_putstr_fd(cmd->cmd_path, 2);
		execve(cmd->cmd_path, cmd->cmd_args, minishell->envp);
	}
	// else if (cmd->cmd_type == BUILT_IN)
}

int	wait_for_children_to_end(int exit_status)
{
	int	status;
	int	i;

	i = 0;

	while (i < 3)
	{
		waitpid(-1, &status, 0);
		if (WIFEXITED(status))
			exit_status = WEXITSTATUS(status);
		i++;
		fprintf(stderr, "exit_status = %d\n", exit_status);
	}
	return (exit_status);
}