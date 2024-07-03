/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operand_redirection_utils.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anastruc <anastruc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 16:30:09 by anastruc          #+#    #+#             */
/*   Updated: 2024/07/03 16:51:09 by anastruc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/minishell.h"

void	file_in_existing(t_redir_file *tmp_file_in, t_cmd *cmd, t_data *minishell)
{
	if (tmp_file_in->next == NULL)
		cmd->infilefd = open(tmp_file_in->file_name, O_RDONLY);
	if (tmp_file_in->redir_type == HERE_DOC)
		unlink(tmp_file_in->file_name);
}

void	file_in_unexisting_or_access_denied(t_redir_file *tmp_file_in,
		t_cmd *cmd, t_data *minishell)
{
	if (errno == EACCES)
		err_msg(PERMISSION_DENIED, tmp_file_in->file_name);
	if (errno == ENOENT)
		err_msg(NO_SUCH_FILE, tmp_file_in->file_name);
	close_fd(cmd);
	clean_all(minishell);
	exit(1);
}

void	file_out_existing(t_redir_file *tmp_file_out, t_cmd *cmd, t_data *minishell)
{
		ft_putstr_fd("HELLO\n", 2);
	if (tmp_file_out->redir_type == APPEND)
	{
		cmd->outfilefd = open(tmp_file_out->file_name, O_WRONLY | O_APPEND);
	}
	else if (cmd->file_out->redir_type == DST_REDIR)
		cmd->outfilefd = open(tmp_file_out->file_name, O_WRONLY);
}
void	file_out_unexisting_or_access_denied(t_redir_file *tmp_file_out,
		t_cmd *cmd, t_data *minishell)
{
	if (errno == EACCES)
	{
		close_fd(cmd);
		exit(err_msg(PERMISSION_DENIED, tmp_file_out->file_name));
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