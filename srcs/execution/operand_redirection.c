/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operand_redirection.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anastruc <anastruc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 14:16:57 by anastruc          #+#    #+#             */
/*   Updated: 2024/07/01 11:21:25 by anastruc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/minishell.h"


void	check_file_in (t_cmd *cmd)
{
	t_redir_file *tmp_file_in;
	if (cmd->file_in)
	{
		tmp_file_in = cmd->file_in;
		while (tmp_file_in)
		{
			if (access(tmp_file_in->file_name, O_RDONLY) == 0)
				{
					ft_putstr_fd("Ouverture fichier OK\n", 2);
					if (tmp_file_in->next == NULL)
						cmd->infilefd = open (tmp_file_in->file_name, O_RDONLY);
				}
			else
			{
				ft_putstr_fd(tmp_file_in->file_name, 2);
				if (errno == EACCES)
					ft_putstr_fd(":Permission denied\n", 2);
				if (errno == ENOENT)
					ft_putstr_fd(":ICINo such file or directory\n", 2);
				close_fd(cmd);
				clean_all();
				exit (1);
			}
			tmp_file_in = tmp_file_in->next;
		}
	}
}

void	check_file_out (t_cmd *cmd)
{
	t_redir_file *tmp_file_out;
	if (cmd->file_out)
	{
		tmp_file_out = cmd->file_out;
		while (tmp_file_out)
		{
			if (access(tmp_file_out->file_name, R_OK) == 0)
				ft_putstr_fd("Le fichier d'OUTFILE existe et est accessible\n", 2);
			else
			{
				if (errno == EACCES)
				{
					ft_putstr_fd(": Permission denied\n", 2);
					close_fd(cmd);
					exit (1);
				}
				else if (errno == ENOENT && cmd->file_out->redir_type == APPEND)
					cmd->outfilefd = open (tmp_file_out->file_name, O_WRONLY | O_CREAT | O_APPEND);
				/*PROTECT OPEN*/
				else if (errno == ENOENT && cmd->file_out->redir_type != APPEND)
					cmd->outfilefd = open (tmp_file_out->file_name, O_WRONLY | O_CREAT);
			}
			tmp_file_out = tmp_file_out->next;
		}
	}
}

void	check_operand_file(t_cmd *cmd)
{
	check_file_in(cmd);
	check_file_out(cmd);
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
