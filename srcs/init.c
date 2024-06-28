/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsalomon <fsalomon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 12:22:39 by fsalomon          #+#    #+#             */
/*   Updated: 2024/06/28 12:23:09 by fsalomon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

void	ft_init_data(char *envp[])
{
	static t_data	*minishell;

	minishell = get_data();
	ft_bzero(minishell, sizeof(t_data));
	minishell->env = get_env(envp);
	// return (minishell);
}
