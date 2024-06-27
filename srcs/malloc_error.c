/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anastruc <anastruc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 11:19:03 by fsalomon          #+#    #+#             */
/*   Updated: 2024/06/27 16:15:53 by anastruc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"


void		malloc_error(void)
{
	t_data *minishell;

	minishell = get_data();
	if (minishell->cmd_list)
		lst_cmd_clear(minishell->cmd_list);
	if (minishell->env)
		lst_env_clear(minishell->env);

	minishell = NULL;
	exit(EXIT_FAILURE);
}

void	malloc_error_env(t_env *lst_env, int fd)
{
	if (fd != -1)
		close (fd);
	lst_env_clear(lst_env);
	malloc_error();

}

