/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anastruc <anastruc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 14:19:29 by anastruc          #+#    #+#             */
/*   Updated: 2024/06/27 11:33:19 by anastruc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"


t_env	*get_partial_env(void)
{
	t_env	*lst_env;
	int		i;
	char	*etc_line;
	int		fd;

	lst_env = NULL;
	etc_line = malloc(sizeof(char *) + 1);
	//gerer le malloc
	fd = open("/etc/environment", O_RDONLY);
	//gerer le error open
	while (1)
	{
		etc_line = get_next_line(fd);
		if (etc_line == NULL)
			break ;
		i = 0;
		while (etc_line[i] != '\0' && etc_line[i] != '=')
			i++;
		ft_lstenvadd_back(&lst_env, create_new_node(i, etc_line));
		// free(etc_line);
	}
	// free(etc_line);
	return (lst_env);
}

t_env	*get_env(char *envp[])
{
	t_env	*lst_env;
	int		i;
	int		j;

	i = 0;
	j = 0;
	lst_env = NULL;
	if (envp[0] == NULL)
		return (get_partial_env());
	while (envp[i])
	{
		while (envp[i][j] != '\0' && envp[i][j] != '=')
			j++;
		ft_lstenvadd_back(&lst_env, create_new_node(j, envp[i]));
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
