/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsalomon <fsalomon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 12:37:03 by fsalomon          #+#    #+#             */
/*   Updated: 2024/06/29 14:45:27 by fsalomon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/minishell.h"

 // Je te change lexit status de la commande dans lenfant tu devras le recuperer dans le parent
 //Si je return exit success il faut auitter le programme si cest failure non 
int exit_with_args(char **args, t_data *data, long long *arg_exit)
{
	if (!it_is_only_digit(args[1]) || there_is_an_overflow(args[1],
				arg_exit))
		{
			data->exit_status = 2;
			ft_putstr_fd("exit\n", STDOUT_FILENO);
			ft_print_exit_error(2, args[1]);
			return (EXIT_SUCCESS);
		}
		else if (args[2])
		{
			ft_print_exit_error(EXIT_FAILURE, args[1]);
			return (EXIT_FAILURE);
		}
		else
		{
			data->exit_status = *arg_exit % 256;
			ft_putstr_fd("exit\n", STDOUT_FILENO);
			return (EXIT_SUCCESS);
		}
}

int	ft_exit(char **args, t_data *data)
{
	long long	arg_exit;

	arg_exit = 0;
	if (args[1])
		return(exit_with_args(args, data, &arg_exit));
	else
	{
		ft_putstr_fd("exit\n", STDOUT_FILENO);
		return (EXIT_SUCCESS);
	}
}

// int main (int argc, char **argv)
// {
// 	t_data 	data;

// 	(void)argc;
// 	ft_exit(argv, &data);
// 	unit_test(&data);
// 	return (1);
// }