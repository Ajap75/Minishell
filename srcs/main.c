/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsalomon <fsalomon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 11:19:18 by fsalomon          #+#    #+#             */
/*   Updated: 2024/06/27 12:23:02 by fsalomon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../headers/minishell.h"

int	main(int argc, char **argv, char *envp[])
{
	static t_data minishell;

	ft_init_data();
	unit_test(&minishell);
	(void)argc;
	(void)argv;
	(void)envp;
	return (1);
}