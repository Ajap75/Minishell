/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anastruc <anastruc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 11:19:03 by fsalomon          #+#    #+#             */
/*   Updated: 2024/07/04 12:15:50 by anastruc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

void clean_all(t_data *minishell)
{

	if (minishell->cmd_list)
		lst_cmd_clear(minishell->cmd_list);
	if (minishell->env)
		lst_env_clear(minishell->env);
	if (minishell)
		free(minishell);
	minishell = NULL;
}
void		malloc_error(t_data *minishell)
{
	if (minishell)
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

