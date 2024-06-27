/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_cmd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsalomon <fsalomon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 17:00:23 by fsalomon          #+#    #+#             */
/*   Updated: 2024/06/27 12:32:24 by fsalomon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

t_cmd	*lst_cmd_new_node(void)
{
	t_cmd	*new;

	new = ft_calloc(sizeof(t_cmd), 1);
	if (!new)
		return (NULL);
	new->infilefd = -1;
	new->outfilefd = -1;
	new->last_pipe_read_end = -1;
	return (new);
}

t_cmd	*lst_cmd_last(t_cmd *cmd_list)
{
	t_cmd	*tmp;

	if (!cmd_list)
		return (NULL);
	tmp = cmd_list;
	while (tmp->next)
		tmp = tmp->next;
	return (tmp);
}

void	lst_cmd_addback(t_cmd **cmd_list, t_cmd *new_node)
{
	t_cmd	*last;

	if (!cmd_list || !new_node)
		return ;
	if (!*cmd_list)
		*cmd_list = new_node;
	else
	{
		last = lst_cmd_last(*cmd_list);
		last->next = new_node;
		new_node->prev = last;
	}
}

void	lst_cmd_clear(t_cmd *cmd_list)
{
	t_cmd	*tmp;

	while (cmd_list)
	{
		tmp = cmd_list;
		cmd_list = cmd_list->next;
		if (tmp->cmd_name)
			free(tmp->cmd_name);
		if (tmp->cmd_args)
			ft_free_split(tmp->cmd_args);
		// lst_redir_clear(file_in)
		// lst_redir_clear(file_out)
		free(tmp);
	}
}
