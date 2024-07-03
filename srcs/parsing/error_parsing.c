/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_parsing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsalomon <fsalomon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 15:37:43 by fsalomon          #+#    #+#             */
/*   Updated: 2024/07/03 16:47:39 by fsalomon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/minishell.h"
#include "../../headers/parsing.h"

void	stop_here_doc(char *delimiter, int i)
{
	char *number_i;
	
		number_i = ft_itoa(i);
		ft_putstr_fd("bash: warning: here-document at line ", STDOUT_FILENO);
		ft_putstr_fd(number_i, STDOUT_FILENO);
		ft_putstr_fd(" delimited by end-of-file (wanted `", STDOUT_FILENO);
		ft_putstr_fd(delimiter, STDOUT_FILENO);
		ft_putstr_fd("')\n", STDOUT_FILENO);
		free(number_i);
}

void	error_parsing(int flag, char *token, t_data *minishell)
{
	if (flag == SYNTAX_ERROR)
	{
		ft_putstr_fd("error bash: syntax error near unexpected token '",
			STDOUT_FILENO);
		ft_putstr_fd(token, STDOUT_FILENO);
		ft_putstr_fd(" ' ", STDOUT_FILENO);
		clean_all(minishell);
		exit(2);
	}
	else if (flag == HERE_STRING_ERROR)
	{
		ft_putstr_fd("error: This shell do not handle here_string",
			STDOUT_FILENO);
		clean_all(minishell);
		exit(2);
	}
	return ;
}