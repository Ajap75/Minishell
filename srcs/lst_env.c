/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anastruc <anastruc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 14:19:29 by anastruc          #+#    #+#             */
/*   Updated: 2024/06/26 17:56:14 by anastruc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

void	print_env_node(t_env *node)
{
	printf("Var_name : %s\n", node->var_name);
	printf("Var_value : %s\n\n", node->var_value);
}

void	print_env_lst(t_env *node)
{
	t_env	*tmp;

	tmp = node;
	while (tmp)
	{
		print_env_node(tmp);
		tmp = tmp->next;
	}
}

int	main(int argc, char **argv, char *envp[])
{
	t_env	*lst_env;

	(void)argv;
	if (argc >= 1)
	{
		lst_env = get_env(envp);
		print_env_lst(lst_env);
	}
	return (0);
}

t_env	*init_node_env(void *var_name, void *var_value)
{
	t_env	*new;

	new = malloc(sizeof(*new));
	if (!new)
		return (NULL);
	new->var_name = var_name;
	new->var_value = var_value;
	new->next = NULL;
	return (new);
}

void	ft_envadd_back(t_env **env_lst, t_env *new_node)
{
	t_env	*current;

	if (env_lst)
	{
		if (*env_lst)
		{
			current = *env_lst;
			while (current->next)
			{
				current = current->next;
			}
			current->next = new_node;
		}
		else
		{
			if (new_node == NULL)
				*env_lst = NULL;
			else
				*env_lst = new_node;
		}
	}
}

t_env	*create_new_node(int j, char *envp)
{
	char	*var_name;
	char	*var_value;

	var_name = ft_substr(envp, 0, j);
	var_value = ft_substr(envp, (j + 1), (ft_strlen(envp) - j));
	if (var_value[0] == '"')
		var_value = ft_substr(envp, (j + 1), (ft_strlen(envp) - 1));
	return (init_node_env(var_name, var_value));
}

t_env	*get_partial_env(void)
{
	t_env	*lst_env;
	t_env	*new;
	int		i;
	char	*etc_line;
	int		fd;

	lst_env = NULL;
	etc_line = malloc(sizeof(char *) + 1);
	fd = open("/etc/environment", O_RDONLY);
	while (1)
	{
		etc_line = get_next_line(fd);
		if (etc_line == NULL)
			break ;
		i = 0;
		while (etc_line[i] != '\0' && etc_line[i] != '=')
			i++;
		new = create_new_node(i, etc_line);
		ft_envadd_back(&lst_env, new);

	}
	printf("prout\n");
	return (lst_env);
}
t_env	*get_env(char *envp[])
{
	t_env *lst_env;
	int i;
	int j;

	i = 0;
	j = 0;
	lst_env = NULL;
	if (envp[0] == NULL)
		return (get_partial_env());
	while (envp[i])
	{
		while (envp[i][j] != '\0' && envp[i][j] != '=')
			j++;
		ft_envadd_back(&lst_env, create_new_node(j, envp[i]));
		j = 0;
		i++;
	}
	return (lst_env);
}