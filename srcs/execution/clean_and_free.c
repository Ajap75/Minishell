/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_and_free.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anastruc <anastruc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 14:29:56 by anastruc          #+#    #+#             */
/*   Updated: 2024/07/01 11:39:25 by anastruc         ###   ########.fr       */
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