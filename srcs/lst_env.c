/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anastruc <anastruc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 14:19:29 by anastruc          #+#    #+#             */
/*   Updated: 2024/06/21 17:57:34 by anastruc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

typedef struct s_env
{
	char			*var_name;
	char			*var_value;
	struct s_env	*prev;
	struct s_env	*next;
}					t_env;

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
t_env	**ft_create_lst_env(char *envp[])
{
	t_env	**lst_env;
	t_env	*new;
	char	**env;
	char	*var_name;
	char	*var_value;
	int		len;
	int		i;

	env = NULL;
	if (envp == NULL)
		env = ft_get_partial_env();
	else
		env = ft_get_full_env(envp);
	while (*env)
	{
		i = 0;
		len = ft_strlen(*env);
		while (*env[i] != '=' && *env[i])
			i++;
		var_name = ft_substr(*env, 0, i);
		var_value = ft_substr(*env, (len - i), len);
		new = ft_lstnew_node_env(var_name, var_value);
		ft_lstadd_back(lst_env, new);
		free(var_name);
		free(var_value);
		env++;
	}
	return (lst_env);
}

char	**ft_get_partial_env(void)
{
	char	**partial_env;
	int		etc_env_fd;
	char 	*line;
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

char	**ft_get_full_env(char **envp)
{
	char	**full_env;

	full_env = NULL;
	full_env = ft_split(envp, "\n");
	return (full_env);
}

// int	main(int argc, char **argv)
// {
// 	int len;
// 	int i;

// 	if (argc == 2)
// 	{
// 		len = ft_strlen(argv[1]);
// 		i = 0;

// 		while (argv[1][i] != '=' && argv[1][i])
// 			i++;
// 		printf("var name = %s\n", ft_substr(argv[1], 0, (i)));
// 		printf("var value = %s\n", ft_substr(argv[1], (len - i), len));
// 	}
// 	return (0);
// }