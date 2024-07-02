/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_redirection.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anastruc <anastruc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 12:41:04 by anastruc          #+#    #+#             */
/*   Updated: 2024/07/02 17:59:08 by anastruc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/minishell.h"

void	pipe_redirection(t_cmd *cmd)
{
		write(2, "PIPE_REDIR\n", 12);

	if (cmd->cmd_pos == ONLY_ONE_CMD)
		only_one_cmd_case_pipe_redirection(cmd);
	else if (cmd->cmd_pos == FIRST_CMD)
		first_cmd_case_pipe_redirection(cmd);
	else if (cmd->cmd_pos == BETWEEN_CMD)
		between_cmd_case_pipe_redirection(cmd);
	else if (cmd->cmd_pos == LAST_CMD)
		last_cmd_case_pipe_redirection(cmd);
}

void	only_one_cmd_case_pipe_redirection(t_cmd *cmd)
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
	write (2, "JE RENTRE DANS LA COMMANDE FIRST\n", 34);
}

void	between_cmd_case_pipe_redirection(t_cmd *cmd)
{
	close(cmd->pipe[0]);
	fprintf(stderr, "%d\n" ,cmd->last_pipe_read_end);
	if (dup2(cmd->last_pipe_read_end, STDIN_FILENO) == -1)
		exit(EXIT_FAILURE);
	write (2, "JE RENTRE DANS LA COMMANDE_BTW\n", 32);
	close(cmd->last_pipe_read_end);
	if (dup2(cmd->pipe[1], STDOUT_FILENO) == -1)
		exit(EXIT_FAILURE);
	close(cmd->pipe[1]);

}

void	last_cmd_case_pipe_redirection(t_cmd *cmd)
{
	close(cmd->pipe[1]);
	close(cmd->pipe[0]);
	if (dup2(cmd->last_pipe_read_end, STDIN_FILENO) == -1)
		exit(EXIT_FAILURE);
	close(cmd->last_pipe_read_end);
		write (2, "JE RENTRE DANS LA COMMANDE_LAST\n", 33);

}
