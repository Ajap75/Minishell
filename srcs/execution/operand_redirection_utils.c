/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operand_redirection_utils.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anastruc <anastruc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 16:30:09 by anastruc          #+#    #+#             */
/*   Updated: 2024/07/02 17:39:04 by anastruc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/minishell.h"

void	file_in_existing(t_redir_file *tmp_file_in, t_cmd *cmd)
{
	write(2, "Ouverture fichier OK\n", 22);
	if (tmp_file_in->next == NULL)
		cmd->infilefd = open(tmp_file_in->file_name, O_RDONLY);
}

void	file_in_unexisting_or_access_denied(t_redir_file *tmp_file_in,
		t_cmd *cmd)
{
	if (errno == EACCES)
		err_msg(PERMISSION_DENIED, tmp_file_in->file_name);
	if (errno == ENOENT)
		err_msg(NO_SUCH_FILE, tmp_file_in->file_name);
	close_fd(cmd);
	clean_all();
	exit(1);
}

void	file_out_existing(t_redir_file *tmp_file_out, t_cmd *cmd)
{
	write(2, "FILE OUT EXIST\n", 16);
	if (tmp_file_out->redir_type == APPEND)
	{
		cmd->outfilefd = open(tmp_file_out->file_name, O_WRONLY | O_APPEND);
	}
	else if (cmd->file_out->redir_type == DST_REDIR)
		cmd->outfilefd = open(tmp_file_out->file_name, O_WRONLY);
}
void	file_out_unexisting_or_access_denied(t_redir_file *tmp_file_out,
		t_cmd *cmd)
{
	write(2, "FILE OUT UNEXISTING\n", 21);
	if (errno == EACCES)
	{
		close_fd(cmd);
		exit(err_msg(PERMISSION_DENIED, cmd->cmd_name));
	}
	else if (errno == ENOENT && tmp_file_out->redir_type == APPEND)
	{
		cmd->outfilefd = open(tmp_file_out->file_name,
				O_WRONLY | O_APPEND | O_CREAT | 0644);
	}
	/*PROTECT OPEN*/
	else if (errno == ENOENT && tmp_file_out->redir_type == DST_REDIR)
	{
		cmd->outfilefd = open(tmp_file_out->file_name,
				O_WRONLY | O_CREAT | 0644);
	}
}

/*SRC_FILE < (FILE_IN) : If one of the src file does not exist (NO_SUCH_FILE),
	the cmd must not be executed. Same thing if the access of one of the infile is denied(ACCESS_DENIED).
DST_FILE > (FILE_OUT) : If one of the OUTFILE does not exist,
	the prog must create it and so on. If the access (PERMISSION DENIED) of one of the outfile is denied,
	the cmd must not be executed*/