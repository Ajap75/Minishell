/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsalomon <fsalomon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 12:37:03 by fsalomon          #+#    #+#             */
/*   Updated: 2024/06/18 15:13:22 by fsalomon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/minishell.h"


//INFORMATION
// Exit peut etre envoyer seul ou avec un seul argument
// Exit seule renvoie l'exit status de la derniere commande
// Exit avec 1 argument renvoie le nombre modulo 256
// Exit renvoie une erreur si valeur argument inferieur ou superieur a un long long ( 9 223 372 036 854 775 807)
//Exit renvoie une erreur si il a plus d un argument


//TODO
// voir comment quitter le process en cours:
// selon si dans pipeline donc dans enfant exit juste lenfant
// ou directe dans le parents donc exit le shell
//modifier dans lenvp le shell level
// kill les process en cours dans lenfant et les sous enfants ?

// UTILS A ENLEVER ET A APPELER DEPUIS LA LIBFT

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t	i;

	i = 0;
	if (!s1 || !s2)
		return (0);
	while (s1[i] == s2[i] && s1[i] && s2[i])
	{
		i++;
	}
	return (((unsigned char *)s1)[i] - ((unsigned char *)s2)[i]);
}

bool	ft_atoll(const char *arg,  long long  *arg_exit)
{
	int	i;

	i = 0;
	printf("test = %s \n", arg);
	if (!ft_strcmp(arg, "-9223372036854775808"))
	{
		*arg_exit = -9223372036854775807LL - 1;
		return (true);
	}
	if (arg[i] == '-')
		i++;
	while (arg[i] != 0 && arg[i] > 47 && arg[i] < 58)
	{
		if (*arg_exit > (LLONG_MAX / 10) || (*arg_exit == (LLONG_MAX / 10) && (arg[i]
					- '0') > LLONG_MAX % 10))
			return (false);
		*arg_exit = *arg_exit * 10 + (arg[i] - '0');
		i++;
	}
	if (arg[0] == '-')
		*arg_exit = -(*arg_exit);
	return (true);
}
static int	it_is_only_digit(char *arg)
{
	int i;

	i = 0;
	if (arg && arg[0] == '-')
		i ++;
	while (arg && arg[i])
	{
		if (arg[i] < 48 || arg[i] > 57)
			return (0);
		i ++;
	}
	return (1);
}

static int	there_is_an_overflow(char *arg, long long *arg_exit)
{
	if (!ft_atoll(arg, arg_exit))
	{
		*arg_exit = 0;
		return (1);
	}
	else
		return (0);
}

 // FIN UTILS 

void ft_print_exit_error(int error_num, char *args)
{
	if (error_num == 1)
		printf("bash: exit: too many arguments\n");
	else if (error_num == 2)
		printf("bash: exit: %s: numeric argument required\n", args);
}

int		ft_exit(char **args, char *envp[], t_data *data)
{
	long long	arg_exit;

	arg_exit = 0;
	(void)*envp;
	if (args[1] && args[2])
	{
		ft_print_exit_error(EXIT_FAILURE, args[1]);
		// ne doit pas executer lexit 
		return (EXIT_FAILURE);
	}
	else if (args[1])
	{
		if (!it_is_only_digit(args[1]) || there_is_an_overflow(args[1], &arg_exit))
		{
			ft_print_exit_error(2, args[1]);
			data->exit_status = 2;
			//si la commande nest pas dans un pipe line faire un reel exit du shell
			//sinon exit seulement le process enfant 
		}
		data->exit_status = arg_exit % 256;
	}
	//else pas dargument 
			//si la commande nest pas dans un pipe line faire un reel exit du shell
			//sinon exit seulement le process enfant
	printf("MON EXIT STATUS EST = %d \n", data->exit_status);
	if (data->shell_level > 1)
	{
		data->shell_level --;
		// modifier le shel level dans envp ( voir comment faire )
	}
	return (data->exit_status);
}

int main (int argc, char **argv, char *envp[])
{
	t_data 	data;

	data.shell_level = 1;
	(void)argc;
	ft_exit(argv, envp, &data);
	return (1);
}