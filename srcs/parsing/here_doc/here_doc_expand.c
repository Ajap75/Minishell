/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc_expand.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsalomon <fsalomon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 17:13:48 by fsalomon          #+#    #+#             */
/*   Updated: 2024/07/03 16:33:49 by fsalomon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../headers/minishell.h"
#include "../../../headers/parsing.h"

static char	*extract_value(char *expand, char **env)
{
	char	*value;
	int		value_len;
	int		line;
	int		i;
	char	*res;

	line = 0;
	i = 0;
	value = NULL;
	while (env[line])
	{
		res = ft_strnstr(env[line], &expand[1], ft_strlen(env[line]));
		if (res && res == &env[line][i] && res[ft_strlen(&expand[1])] == '=')
		{
			value_len = ft_strlen(env[line]) - (ft_strlen(&expand[1]) + 1);
			value = malloc(sizeof(char) + (value_len + 1));
			res += (ft_strlen(&expand[1]) + 1);
			ft_strlcpy(value, res, value_len + 1);
			return (value);
		}
		line++;
	}
	return (NULL);
}

static char	*get_value(char *expand, t_data *minishell)
{
	char	*value;

	value = extract_value(expand, minishell->envp);
	if (!value)
		return (NULL);
	return (value);
}

static char	*get_expand(char *line)
{
	char	*expand;
	int		i;
	int		len_expand;
	int		index;

	i = 0;
	len_expand = 1;
	while (line[i] != '$')
		i++;
	index = i;
	i++;
	len_expand ++;
	while (line[i] && !is_separator_char(line[i]))
	{
		len_expand++;
		i++;
	}
	expand = malloc(sizeof(char) * (len_expand + 1));
	ft_strlcpy(expand, &line[index], len_expand);
	return (expand);
}

bool	there_is_expand(char *line)
{
	int	i;

	i = 0;
	while (line[i] && line[i] != '$')
		i++;
	if (line[i])
		i++;
	else
		return (false);
	if (is_separator_char(line[i]))
		return (false);
	else
		return (true);
}

char	*change_expand(char *line, t_data *minishell)
{
	char	*expand;
	char	*new_value;
	char	*newline;

	if (there_is_expand(line))
		expand = get_expand(line);
	else
		return (line);
	if (!expand)
		return (free(line), NULL);
	new_value = get_value(expand, minishell);
	if (!new_value)
		return (line);
	newline = put_file_name(line, new_value, expand);
	free(expand);
	free(new_value);
	return (newline);
}
