/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsalomon <fsalomon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 11:19:03 by fsalomon          #+#    #+#             */
/*   Updated: 2024/06/27 12:31:11 by fsalomon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"


void		malloc_error(void)
{
	t_data *minishell;

	minishell = get_data();
	if (minishell->cmd_list->file_in)
		//lst_file_clear(minishell->cmd_list->file_in);
		//lst_file_clear(minishell->cmd_list->file_out);
	if (minishell->cmd_list)
		lst_cmd_clear(minishell->cmd_list);
	if (minishell->env)
		//lst_env_clear(minishell->env);
	
	minishell = NULL;
	return ;
}
