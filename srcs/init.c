/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsalomon <fsalomon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 12:22:39 by fsalomon          #+#    #+#             */
/*   Updated: 2024/07/03 16:52:01 by fsalomon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

t_data	*ft_init_data(char *envp[], t_data *minishell)
{
	minishell = malloc(sizeof(t_data));
	ft_bzero(minishell, sizeof(t_data));
	if (*envp)
		minishell->envp = envp;
	minishell->env = get_env(envp, minishell);
	return (minishell);
}
