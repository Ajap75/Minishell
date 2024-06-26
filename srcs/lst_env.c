/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anastruc <anastruc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 14:19:29 by anastruc          #+#    #+#             */
/*   Updated: 2024/06/26 14:22:16 by anastruc         ###   ########.fr       */
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
	// printf("node\n");
	// fflush(NULL);
	while (tmp)
	{
		print_env_node(tmp);
		tmp = tmp->next;
	}
}
char	**ft_get_partial_env(void)
{
	char	**partial_env;
	int		etc_env_fd;
	char	*line;
	int		i;

	line = NULL;
	i = 0;
	partial_env = NULL;
	etc_env_fd = open("etc/environment", O_RDONLY);
	// gerer le crash de open;
	partial_env[i] = get_next_line(etc_env_fd);
	i++;
	while (partial_env[i])
	{
		partial_env[i] = get_next_line(etc_env_fd);
		i++;
	}
	close(etc_env_fd);
	return (partial_env);
}

// char	**ft_get_full_env(char **envp)
// {
// 	char	**full_env;

// 	full_env = NULL;
// 	full_env = ft_split(envp, "\n");
// 	return (full_env);
// }

t_env	*ft_lstnew_node_env(void *var_name, void *var_value)
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

	// print_env_node(new_node);
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
t_env	*ft_create_lst_env(char *envp[])
{	// lst_env++;

	t_env	*lst_env;
	t_env	*new;
	char	**env;
	char	*var_name;
	char	*var_value;
	int		len;
	int		i;
	int		j;

	i = 0;
	j = 0;
	env = NULL;
	lst_env = NULL;
	if (envp == NULL)
		env = ft_get_partial_env();
	env = envp;
	while (env[i])
	{
		len = ft_strlen(env[i]);
		while (env[i][j] != '\0' && env[i][j] != '=')
			{
				// printf("%c\n", env[i][j]);
				// fflush(NULL);
				j++;
			}
		var_name = ft_substr(env[i], 0, j);
		var_value = ft_substr(env[i], (j + 1), (len - j));
		new = ft_lstnew_node_env(var_name, var_value);
		ft_envadd_back(&lst_env, new);
		// free(var_name);
		// free(var_value);
		j = 0;
		i++;
	}
	// lst_env++;
	print_env_lst(lst_env);
	printf("prout\n");
	fflush(NULL);
	return (lst_env);

}



int	main(int argc, char **argv, char *envp[])
{
	t_env	*lst_env;
	(void)argv;

	if (argc >= 1)
	{
		lst_env = ft_create_lst_env(envp);
		// print_env_lst(lst_env);
	}
	return (0);
}
