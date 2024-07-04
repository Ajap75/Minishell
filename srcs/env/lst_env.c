/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anastruc <anastruc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 14:19:29 by anastruc          #+#    #+#             */
/*   Updated: 2024/07/04 10:14:27 by anastruc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/minishell.h"

static int	open_etc_env(t_data *minishell)
{
	int	fd;

	fd = open("/etc/environment", O_RDONLY);
	if (fd == -1)
		malloc_error(minishell);
	return (fd);
}

static t_env	*get_partial_env(t_env *new, t_data *minishell)
{
	t_env	*lst_env;
	int		i;
	char	*etc_line;
	int		fd;

	lst_env = NULL;
	etc_line = NULL;
	fd = open_etc_env(minishell);
	while (1)
	{
		if (etc_line)
			free(etc_line);
		etc_line = get_next_line_and_init_envp(fd);
		if (etc_line == NULL)
			break ;
		i = 0;
		while (etc_line[i] != '\0' && etc_line[i] != '=')
			i++;
		new = create_new_node(i, etc_line, 1);
		if (new == NULL)
			malloc_error_env(lst_env, fd, minishell);
		ft_lstenvadd_back(&lst_env, new);
	}
	close(fd);
	return (lst_env);
}
char	*get_next_line_and_init_envp(int fd)
{
	t_data		*minishell;
	char		*etc_line;
	static int	i = 0;

	minishell = get_data();
	etc_line = get_next_line(fd);
	if (etc_line)
	{
		if (i == 0)
			minishell->envp = malloc(sizeof(char *) * 2);
		else
			minishell->envp = ft_realloc(minishell->envp, ((2 + i)
						* sizeof(char *)));
		minishell->envp[i] = malloc(sizeof(char) * (ft_strlen(etc_line) + 1));
		minishell->envp[i + 1] = NULL;
		i++;
	}
	return (etc_line);
}
t_env	*get_env(char *envp[], t_data *minishell)
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
		return (get_partial_env(new, minishell));
	while (envp[i])
	{
		while (envp[i][j] != '\0' && envp[i][j] != '=')
			j++;
		new = create_new_node(j, envp[i], 0);
		if (new == NULL)
			malloc_error_env(lst_env, -1, minishell);
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

/*We get the env from to different space. If envp can be access,
	we init the t_env chained list from envp (main). Otherwise we init t_env with datas
from etc/environment. The structure will be used in the exec part to check the accessibility of the command with the PATH= from the env t_env.
However, if the shell is executed with "env -i",
	we need to init a simili envp var (char *envp[]) to replace the actual envp. Why ? In order to execute execve with a (char *envp[]) different from envp[0]=NULL (env
		-i situation).
Now if we execute a minishell in our minishell,
	the second level will inherit of a simili  envp.*/
