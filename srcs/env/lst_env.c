/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anastruc <anastruc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 14:19:29 by anastruc          #+#    #+#             */
/*   Updated: 2024/06/27 16:28:41 by anastruc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/minishell.h"

static int	open_etc_env(void)
{
	int	fd;

	fd = open("/etc/environment", O_RDONLY);
	if (fd == -1)
		malloc_error ();
	return (fd);
}

t_env	*get_partial_env(t_env *new)
{
	t_env	*lst_env;
	int		i;
	char	*etc_line;
	int		fd;

	lst_env = NULL;
	etc_line = NULL;
	fd = open_etc_env();
	while (1)
	{
		if (etc_line)
			free(etc_line);
		etc_line = get_next_line(fd);
		if (etc_line == NULL)
			break ;
		i = 0;
		while (etc_line[i] != '\0' && etc_line[i] != '=')
			i++;
		new = create_new_node(i, etc_line, 1);
		if (new == NULL)
			malloc_error_env(lst_env, fd);
		ft_lstenvadd_back(&lst_env, new);
	}
	close(fd);
	return (lst_env);
}

t_env	*get_env(char *envp[])
{
	t_env	*lst_env;
	int		i;
	int		j;
	t_env	*new;

	i = 0;
	j = 0;
	new = NULL;
	lst_env = NULL;
	if (envp[0] == NULL)
		return (get_partial_env(new));
	while (envp[i])
	{
		while (envp[i][j] != '\0' && envp[i][j] != '=')
			j++;
		new = create_new_node(j, envp[i], 0);
		if (new == NULL)
			malloc_error_env(lst_env, -1);
		ft_lstenvadd_back(&lst_env, new);
		j = 0;
		i++;
	}
	return (lst_env);
}

void	lst_env_clear(t_env *lst_env)
{
	t_env	*tmp;

	while (lst_env)
	{
		tmp = lst_env;
		lst_env = lst_env->next;
		free(tmp->var_name);
		free(tmp->var_value);
		free(tmp);
	}
}
