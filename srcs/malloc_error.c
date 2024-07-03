/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsalomon <fsalomon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 11:19:03 by fsalomon          #+#    #+#             */
/*   Updated: 2024/07/03 16:40:19 by fsalomon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

void clean_all(t_data *minishell)
{

	if (minishell->cmd_list)
		lst_cmd_clear(minishell->cmd_list);
	if (minishell->env)
		lst_env_clear(minishell->env);

	minishell = NULL;
}
void		malloc_error(t_data *minishell)
{
	clean_all(minishell);
	printf("malloc error\n");
	exit(EXIT_FAILURE);
}

void	malloc_error_env(t_env *lst_env, int fd, t_data *minishell)
{
	if (fd != -1)
		close (fd);
	lst_env_clear(lst_env);
	malloc_error(minishell);

}

