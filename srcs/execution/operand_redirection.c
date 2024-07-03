/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operand_redirection.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anastruc <anastruc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 14:16:57 by anastruc          #+#    #+#             */
/*   Updated: 2024/07/03 16:54:25 by anastruc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/minishell.h"

void	operand_redirection(t_cmd *cmd, t_data *minishell)
{
	check_operand_file(cmd, minishell);
	if (cmd->infilefd != -1)
	{
		if (dup2(cmd->infilefd, STDIN_FILENO) == -1)
			close(cmd->infilefd);
	}
	if (cmd->outfilefd != -1)
	{
		if (dup2(cmd->outfilefd, STDOUT_FILENO) == -1)
			close(cmd->outfilefd);
	}
}
void	check_operand_file(t_cmd *cmd, t_data *minishell)
{
	check_file_in(cmd, minishell);
	check_file_out(cmd, minishell);
}
void	check_file_in(t_cmd *cmd, t_data *minishell)
{
	t_redir_file	*tmp_file_in;

	if (cmd->file_in)
	{
		tmp_file_in = cmd->file_in;
		while (tmp_file_in)
		{
			if (access(tmp_file_in->file_name, X_OK) == 0)
				file_in_existing(tmp_file_in, cmd, minishell);
			else
				file_in_unexisting_or_access_denied(tmp_file_in, cmd,
					minishell);
			tmp_file_in = tmp_file_in->next;
		}
	}
}

void	check_file_out(t_cmd *cmd, t_data *minishell)
{
	t_redir_file	*tmp_file_out;

	// fprintf(stderr, "file_out = %s\n", cmd->file_out->file_name);
	if (cmd->file_out)
	{
		tmp_file_out = cmd->file_out;
		while (tmp_file_out)
		{
			if (access(tmp_file_out->file_name, X_OK) == 0)
				file_out_existing(tmp_file_out, cmd, minishell);
			else
				file_out_unexisting_or_access_denied(tmp_file_out, cmd,
					minishell);
			if (tmp_file_out->next && cmd->outfilefd != -1)
				close(cmd->outfilefd);
			tmp_file_out = tmp_file_out->next;
		}
	}
}
