/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_exe.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anastruc <anastruc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 12:41:04 by anastruc          #+#    #+#             */
/*   Updated: 2024/06/28 17:46:04 by anastruc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/minishell.h"

int	main(void)
{
	// return TEST1 fanny
	// return TEST2 fanny
	// ETC
}

void	execution(t_data *minishell)
{
	int		pid;
	t_cmd	*cmd;

	cmd = minishell->cmd_list;
	while (cmd != NULL)
	{
		if (pipe(cmd->pipe) == -1)
			exit(EXIT_FAILURE);
		/*FORK PROCESS FOR EVERY CMD*/
		pid = fork();
		if (pid == -1)
			exit(EXIT_FAILURE);
		if (pid == 0)
		{
			pipe_redirection(cmd);
			operand_redirection(cmd);
		}
		/*LOOP UNTIL THE LAST CMD_NODE*/
		close(cmd->pipe[1]);
		if (cmd->next != NULL)
			cmd->next->last_pipe_read_end = cmd->pipe[0];
		close(cmd->pipe[0]);
		cmd = cmd->next;
	}
	/*WAIT FOR CHILDS TO END */
}

void	pipe_redirection(t_cmd *cmd)
{
	if (cmd->cmd_type == ONLY_ONE_CMD)
		O_O_CMD_case_pipe_redirection(cmd);
	else if (cmd->cmd_type == FIRST_CMD)
		first_cmd_case_pipe_redirection(cmd);
	else if (cmd->cmd_type == BETWEEN_CMD)
		between_cmd_case_pipe_redirection(cmd);
	else if (cmd->cmd_type == LAST_CMD)
		last_cmd_case_pipe_redirection(cmd);
}

void	pipe_redirection_O_O_CMD_case(t_cmd *cmd)
{
	close(cmd->pipe[0]);
	close(cmd->pipe[1]);
}

void	first_cmd_case_pipe_redirection(t_cmd *cmd)
{
	close(cmd->pipe[0]);
	if (dup2(cmd->pipe[1], STDOUT_FILENO) == -1)
		exit(EXIT_FAILURE);
	close(cmd->pipe[1]);
}

void	between_cmd_case_pipe_redirection(t_cmd *cmd)
{
	close(cmd->pipe[0]);
	if (dup2(cmd->last_pipe_read_end, STDIN_FILENO) == -1)
		exit(EXIT_FAILURE);
	close(cmd->last_pipe_read_end);
	if (dup2(cmd->pipe[1], STDOUT_FILENO) == -1)
		exit(EXIT_FAILURE);
	close(cmd->pipe[1]);
}

void	last_cmd_case_pipe_redirection(t_cmd *cmd)
{
	close(cmd->pipe[1]);
	if (dup2(cmd->last_pipe_read_end, STDIN_FILENO) == -1)
		exit(EXIT_FAILURE);
	close(cmd->last_pipe_read_end);
}

void	check_operand_file(t_cmd *cmd)
{
	t_redir_file *tmp_file_in;
	t_redir_file *tmp_file_out;

	if (cmd->file_in)
	{
		tmp_file_in = cmd->file_in;
		while (tmp_file_in)
		{
			if (access(tmp_file_in->file_name, O_RDONLY) == -1)
			{
				ft_putstr_fd("Permission denied\n");
				break;
			}
			else if (open(tmp_file_in, O_RDONLY, ) )

			tmp_file_in = tmp_file_in->next;
		}
	}
	if(cmd->file_out)
}
void	operand_redirection(t_cmd *cmd)
{
	check_operand_file(cmd);
	if (cmd->infilefd != -1)
	{
		if(dup2(cmd->infilefd, STDIN_FILENO) == -1)
			close(cmd->infilefd);
	}
	if (cmd->outfilefd != -1)
	{
		if(dup2(cmd->outfilefd, STDOUT_FILENO) == -1)
			close(cmd->infilefd);
	}
}
