/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_cmd_debug.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anastruc <anastruc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 17:30:54 by fsalomon          #+#    #+#             */
/*   Updated: 2024/07/03 11:02:42 by anastruc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

void	print_cmd_node(t_cmd *node)
{
	int	i;

	i = 0;
	printf("COMMANDE NAME :\n%s\n", node->cmd_name);
	printf("COMMANDE ARGS :\n");
	while (node->cmd_args && node->cmd_args[i])
	{
		printf("args number %d = %s\n", i, node->cmd_args[i]);
		i++;
	}
	printf("COMMANDE POS :\n");
	switch (node->cmd_pos)
	{
	case FIRST_CMD:
		printf("FIRST_CMD\n");
		break ;
	case BETWEEN_CMD:
		printf("BETWEEN_CMD\n");
		break ;
	case LAST_CMD:
		printf("LAST_CMD\n");
		break ;
	case ONLY_ONE_CMD:
		printf("ONLY_ONE_CMD\n");
		break ;
	case -1:
		printf("non initialiser");
		break ;
	default:
		break ;
	}
		printf("COMMANDE type :\n");
	switch (node->cmd_type)
	{
	case CMD:
		printf("CMD\n");
		break ;
	case BUILT_IN:
		printf("BUILT_IN\n");
		break ;
	case NO_CMD:
		printf("NO_CMD\n");
		break ;
	case -1:
		printf("non initialiser");
		break ;
	default:
		break ;
	}
	printf("LISTES FILES IN :\n");
	print_redir_file_lst(node->file_in);
	printf("LISTES FILES OUT :\n");
	print_redir_file_lst(node->file_out);
	printf("infile fd = %d\n", node->infilefd);
	printf("outfile fd = %d\n", node->outfilefd);
	printf("last pipe read end = %d\n", node->last_pipe_read_end);
	printf("\n\n");
}

void	print_cmd_lst(t_cmd *node)
{
	t_cmd	*tmp;

	tmp = node;
	while (tmp)
	{
		print_cmd_node(tmp);
		tmp = tmp->next;
	}
}
