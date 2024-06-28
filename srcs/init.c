/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anastruc <anastruc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 12:22:39 by fsalomon          #+#    #+#             */
/*   Updated: 2024/06/28 10:02:21 by anastruc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

t_data	*ft_init_data(char *envp[])
{
	static t_data	*minishell;

	minishell = malloc(sizeof(t_data));
	minishell = get_data();
	ft_bzero(minishell, sizeof(t_data));
	minishell->env = get_env(envp);
	print_env_lst(minishell->env);
	return (minishell);
}
