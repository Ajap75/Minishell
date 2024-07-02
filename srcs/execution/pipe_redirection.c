/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_redirection.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anastruc <anastruc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 12:41:04 by anastruc          #+#    #+#             */
/*   Updated: 2024/07/02 09:49:56 by anastruc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/minishell.h"

// PLUSIEURS PROBLEME DANS L"INITIALISATION POUR LES TESTE: POUR LE TABLEAU DE CHAINE DE CARACTER< IL FAUT INITIALISER LE DERNIER POINTEUR A NULL. POUR L"ECRITURE DE LA CHAINE
// DE CARACTERE QUI COMPRENDS LE NOM DE LA COMMANDE, IL NE FAUT PAS ECRASER l"ADRESSE PRECEDEMMENT MALLOC EN LA REMPLACANT PAR UNE CHAINE LITTERAL CAR 1) PERTE DE l"ESPACE PRECEDEMENT MALLOC.
// 2) INVALID FREE LORS DE LA LIBERATION DE LA MEMOIRE CAR TENTATIVE DE FREE UNE ZONE MEMOIRE NON ALLOUEE DYNAMIQUEMENT.
// 3) SOLUTION : UTILISER STRCOPY AVEC EN ARGUMENT LA ZONE MEMOIRE ET LA STRING A METTRE DANS CETTE ZONE.


void	init_data_for_test_antoine(void)
{

	t_data	*minishell;
	t_cmd	*cursor;
	minishell = get_data();
	minishell->cmd_list = lst_cmd_new_node();
	minishell->cmd_list->cmd_pos = FIRST_CMD;
	minishell->cmd_list->cmd_type = CMD;
	minishell->cmd_list->cmd_args = malloc(sizeof(char *) * 2);
	minishell->cmd_list->cmd_args[0] = malloc(sizeof(char)* (ft_strlen("ls") + 1));
	minishell->cmd_list->cmd_name = malloc(sizeof(char)* (ft_strlen("ls") + 1));
	strcpy(minishell->cmd_list->cmd_name, "ls");
	strcpy(minishell->cmd_list->cmd_args[0], "ls");
	minishell->cmd_list->cmd_args[1] = NULL;
	minishell->cmd_list->file_in = init_node_lst_file(SRC_REDIR, "infile1");
	lst_redir_file_addback(&minishell->cmd_list->file_in, init_node_lst_file(SRC_REDIR, "infile2"));
	lst_redir_file_addback(&minishell->cmd_list->file_in, init_node_lst_file(SRC_REDIR, "infile3"));
	cursor = lst_cmd_new_node();
	cursor->cmd_pos = BETWEEN_CMD;
	cursor->cmd_name = malloc(sizeof(char)* (ft_strlen("cat") + 1));
	strcpy(cursor->cmd_name, "ls");
	cursor->cmd_type = CMD;
	cursor->cmd_args = malloc(sizeof(char *) * 2);
	cursor->cmd_args[0] = malloc(sizeof(char)* (ft_strlen("cat") + 1));
	strcpy(cursor->cmd_args[0], "cat");
	cursor->cmd_args[1] = NULL;
	lst_cmd_addback(&(minishell->cmd_list), cursor);
	cursor = lst_cmd_new_node();
	cursor->cmd_pos = LAST_CMD;
	cursor->cmd_type = CMD;
	cursor->cmd_name = malloc(sizeof(char)* (ft_strlen("cat") + 1));
	strcpy(cursor->cmd_name, "ls");
	cursor->cmd_args = malloc(sizeof(char *) * 2);
	cursor->cmd_args[0] = malloc(sizeof(char)* (ft_strlen("cat") + 1));
	strcpy(cursor->cmd_args[0], "cat");
	cursor->cmd_args[1] = NULL;
	cursor->file_out = init_node_lst_file(DST_REDIR, "outfile1");
	lst_redir_file_addback(&cursor->file_out, init_node_lst_file(DST_REDIR, "outfile2"));
	lst_redir_file_addback(&cursor->file_out, init_node_lst_file(APPEND, "outfile3"));
	lst_cmd_addback(&(minishell->cmd_list), cursor);
}

void	execution(t_data *minishell)
{
	int		pid;
	t_cmd	*cmd;
	int	status;
	int	i;
	i = 0;

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
		}
		/*LOOP UNTIL THE LAST CMD_NODE*/
		close(cmd->pipe[1]);
		if (cmd->next != NULL)
			cmd->next->last_pipe_read_end = cmd->pipe[0];
		// close (cmd->pipe[0]);
		cmd = cmd->next;
	}
	clean_all();

	while (i < 3)
	{
		waitpid(-1, &status, 0);
		i++;
	}
	/*WAIT FOR CHILDS TO END */
}

void	pipe_redirection(t_cmd *cmd)
{
	if (cmd->cmd_pos == ONLY_ONE_CMD)
		O_O_CMD_case_pipe_redirection(cmd);
	else if (cmd->cmd_pos == FIRST_CMD)
		first_cmd_case_pipe_redirection(cmd);
	else if (cmd->cmd_pos == BETWEEN_CMD)
		between_cmd_case_pipe_redirection(cmd);
	else if (cmd->cmd_pos == LAST_CMD)
		last_cmd_case_pipe_redirection(cmd);
}

void	O_O_CMD_case_pipe_redirection(t_cmd *cmd)
{
	close(cmd->pipe[0]);
	close(cmd->pipe[1]);
}

void	first_cmd_case_pipe_redirection(t_cmd *cmd)
{
	t_data	*minishell;
	minishell = get_data();
	close(cmd->pipe[0]);
	if (dup2(cmd->pipe[1], STDOUT_FILENO) == -1)
		exit(EXIT_FAILURE);
	close(cmd->pipe[1]);
	operand_redirection(cmd);
	exec(cmd);
	clean_all();
	// FREE and CLOSE
}

void	between_cmd_case_pipe_redirection(t_cmd *cmd)
{
	t_data	*minishell;


	minishell = get_data();
	close(cmd->pipe[0]);
	if (dup2(cmd->last_pipe_read_end, STDIN_FILENO) == -1)
		exit(EXIT_FAILURE);
	close(cmd->last_pipe_read_end);
	if (dup2(cmd->pipe[1], STDOUT_FILENO) == -1)
		exit(EXIT_FAILURE);
	close(cmd->pipe[1]);
	operand_redirection(cmd);
	exec(cmd);
	clean_all();

	// FREE and CLOSE

}

void	last_cmd_case_pipe_redirection(t_cmd *cmd)
{
	t_data	*minishell;
	// int	fd;

	minishell = get_data();
	close(cmd->pipe[1]);
	if (dup2(cmd->last_pipe_read_end, STDIN_FILENO) == -1)
		exit(EXIT_FAILURE);
	close(cmd->last_pipe_read_end);
	// fd = open("BIN1", O_RDWR | O_CREAT, 0777);
	// if (dup2(fd, STDOUT_FILENO) == -1)
	// 	exit(EXIT_FAILURE);
	operand_redirection(cmd);
	// ft_putstr_fd("argv = %s\n, ");
	exec(cmd);
	clean_all();
	// FREE and CLOSE


}
