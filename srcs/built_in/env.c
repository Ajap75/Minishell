/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsalomon <fsalomon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 12:09:52 by fsalomon          #+#    #+#             */
/*   Updated: 2024/06/16 12:37:13 by fsalomon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/minishell.h"

static void	ft_putendl_fd(char *s, int fd)
{
	int	i;

	if (!s)
		return ;
	i = 0;
	while (s[i] != 0)
	{
		write(fd, &s[i], 1);
		i++;
	}
	write(fd, "\n", 1);
}

void	env(char *envp[], int fd)
{
	int i;

	i = 0;
	while (*envp != NULL)
	{
		ft_putendl_fd(*envp, fd);
		envp ++;
	}
	return ;
}


// int main (int argc, char **argv, char *envp[])
// {
// 	(void)argc;
// 	(void)argv;
// 	env(envp, STDOUT_FILENO);
// 	return (1);
// }