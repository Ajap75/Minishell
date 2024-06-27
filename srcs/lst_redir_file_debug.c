/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_redir_file_debug.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anastruc <anastruc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 11:48:17 by anastruc          #+#    #+#             */
/*   Updated: 2024/06/27 16:33:29 by anastruc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"


t_redir_file	*init_redir_file_lst(int a, int b, int c, char *aa, char *bb, char *cc)
{
	t_redir_file *file_lst;
	t_redir_file *node1;
	t_redir_file *node2;
	t_redir_file *node3;

	file_lst = NULL;
	node1 = init_node_lst_file(a, aa);
	node2 = init_node_lst_file(b, bb);
	node3 = init_node_lst_file(c, cc);
	lst_redir_file_addback(&file_lst, node1);
	lst_redir_file_addback(&file_lst, node2);
	lst_redir_file_addback(&file_lst, node3);

	return(file_lst);
}

void	print_redir_file_node(t_redir_file *node)
{
	printf("file name: %s\n", node->file_name);
	printf("file redir type : %d\n\n", node->redir_type);
}

void	print_redir_file_lst(t_redir_file *node)
{
	t_redir_file	*tmp;

	tmp = node;
	printf("tmp = %p\n", tmp);
	while (tmp)
	{
		print_redir_file_node(tmp);
		tmp = tmp->next;
	}
}

// int	main(int argc, char **argv)
// {
// 	t_redir_file	*lst_redir_file;

// 	lst_redir_file = NULL;

// 	if (argc >= 1)
// 	{

// 		lst_redir_file = init_redir_file_lst(ft_atoi(argv[1]), ft_atoi(argv[2]), ft_atoi(argv[3]), argv[4], argv[5], argv[6]);
// 		print_redir_file_lst(lst_redir_file);
// 		lst_redir_file_clear(lst_redir_file);
// 	}
// 	return (0);
// }
