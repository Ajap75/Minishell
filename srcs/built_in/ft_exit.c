/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsalomon <fsalomon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 12:37:03 by fsalomon          #+#    #+#             */
/*   Updated: 2024/06/25 11:41:27 by fsalomon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/minishell.h"


//INFORMATION
// Exit peut etre envoyer seul ou avec un seul argument
// Exit seule renvoie l'exit status de la derniere commande
// Exit avec 1 argument renvoie le nombre modulo 256
// Exit renvoie une erreur si valeur argument inferieur ou superieur a un long long ( 9 223 372 036 854 775 807)
// Exit renvoie une erreur si il a plus d un argument


//TODO
// voir comment quitter le process en cours:
// selon si dans pipeline donc dans enfant exit juste lenfant
// ou directe dans le parents donc exit le shell
// modifier dans lenvp le shell level
// kill les process en cours dans lenfant et les sous enfants ?

int	ft_exit(char **args, t_data *data)
{
	long long	arg_exit;

	arg_exit = 0;
	if (args[1])
	{
		if (!it_is_only_digit(args[1]) || there_is_an_overflow(args[1], &arg_exit))
		{
			ft_print_exit_error(2, args[1]);
			data->exit_status = 2;
			//effectuer lexit
		}
		else if (!args[2])
			data->exit_status = arg_exit % 256;
			// effectuer lexit
	}
	else if (args[1] && args[2])
	{
		ft_print_exit_error(EXIT_FAILURE, args[1]);
		// ne doit pas executer lexit 
		return (EXIT_FAILURE);
	}
	//else pas dargument 
			//exit(data->exit_status)
	exit (data->exit_status);
}

// int main (int argc, char **argv, char *envp[])
// {
// 	t_data 	data;

// 	data.shell_level = 1;
// 	(void)argc;
// 	ft_exit(argv, envp, &data);
// 	return (1);
// }