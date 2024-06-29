/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsalomon <fsalomon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 16:58:05 by fsalomon          #+#    #+#             */
/*   Updated: 2024/06/29 17:09:20 by fsalomon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/minishell.h"
#include "../../headers/parsing.h"

char	*put_file_name(char *input)
{
	// creer une nouvelle ligne avec le nom de file du here_doc a la place du delimiter et la renvoyer (free l'ancienne)
	return (input);
}

char	*get_random_name(char **env)
{
	// creer un nom aleatoire et le return
}

int	create_heredoc_file(t_redir_file *here_doc)
{
	int		fd;
	t_data	*minishell;

	minishell = Get_data();
	here_doc->file_name = get_random_name(minishell->env);
	fd = open(here_doc->file_name, O_CREAT, O_APPEND, O_RDWR, O_TRUNC);
	return (fd);
}

char	*get_delimiter(char *input)
{
	// chercher le <<
	// espace ou pas et prendre la suite de charactere dapres
	// si quotes prendre les espaces si | ou autres redirection fin du delimiter
}

bool	is_it_delimiter(char *line, char *del)
{
	if (ft_strcmp(line, del) == 0)
		return (true);
	else
		return (false);
}
