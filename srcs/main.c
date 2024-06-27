/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anastruc <anastruc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 11:19:18 by fsalomon          #+#    #+#             */
/*   Updated: 2024/06/27 17:13:46 by anastruc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../headers/minishell.h"

int	main(int argc, char **argv, char *envp[])
{
	static t_data *minishell;
	minishell = malloc(sizeof(t_data));

	minishell = ft_init_data(envp);
	printf("ENVP : \n%s\n", minishell->env->var_name);
	(void)argc;
	(void)argv;
	(void)envp;
	return (1);
}