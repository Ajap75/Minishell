/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anastruc <anastruc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 14:16:05 by anastruc          #+#    #+#             */
/*   Updated: 2024/07/02 10:00:22 by anastruc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/minishell.h"

void	exec(t_cmd *cmd)
{
		printf("ICI\n");

	t_data *minishell;

	minishell = get_data();
	if (cmd->cmd_type == CMD)
	{
		find_cmd_path(cmd, minishell);
		ft_putstr_fd("\n", 2);
		ft_putstr_fd(cmd->cmd_path, 2);
		if (ft_strchr(cmd->cmd_name, '/'))
			cmd->cmd_path = cmd->cmd_name;
		if (cmd->cmd_path == NULL)
		{
			write(2, "ICI\n", 5);
			exit(err_msg(CMD_NOT_FOUND, cmd->cmd_name));
		}
		printf("Execution de : %s, en %d position\n", cmd->cmd_name, cmd->cmd_pos);
		execve(cmd->cmd_path, cmd->cmd_args, minishell->envp);
	}
	// else if (cmd->cmd_type == BUILT_IN)
}


void	find_cmd_path (t_cmd *cmd, t_data *minishell)
{
	t_env	*tmp;
	char **possible_path_tab;
	int	i;
	char	*final_path;

	i = 0;
	tmp = minishell->env;
	while (tmp && strcmp(tmp->var_name, "PATH") != 0)
		tmp = tmp->next;
	possible_path_tab = ft_split(tmp->var_value, ':');
	while (possible_path_tab[i])
	{
		final_path = create_path(possible_path_tab[i], "/", cmd->cmd_name);
		if (access(final_path, F_OK | X_OK) == 0)
		{
			cmd->cmd_path = final_path;
			write (2, "OK acces\n", 10);
			break;
		}
		i++;
	}
	ft_free_split(possible_path_tab);
}

char *create_path(char *s1, char *s2, char *s3)
{
	char	*newstring;
	int		i;
	int		length;

	if (!s1 || !s2 || !s3)
		return (NULL);
	length = ft_strlen((char *)s1) + ft_strlen((char *)s2) + ft_strlen((char *)s3);
	newstring = malloc(sizeof(char) * (length + 1));
	if (!newstring)
		return (NULL);
	i = 0;
	while (*s1)
		newstring[i++] = *s1++;
	while (*s2)
		newstring[i++] = *s2++;
	while (*s3)
		newstring[i++] = *s3++;
	newstring[i] = '\0';
	return (newstring);
}


