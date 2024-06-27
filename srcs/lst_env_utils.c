/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_env_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anastruc <anastruc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 11:18:34 by anastruc          #+#    #+#             */
/*   Updated: 2024/06/27 11:26:35 by anastruc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

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

void	ft_lstenvadd_back(t_env **env_lst, t_env *new_node)
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
		var_value = ft_substr(var_value, 1, (ft_strlen(var_value) - 3));
	return (init_node_env(var_name, var_value));
}
