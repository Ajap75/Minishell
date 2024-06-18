/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsalomon <fsalomon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 14:21:29 by fsalomon          #+#    #+#             */
/*   Updated: 2024/06/18 15:14:15 by fsalomon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <errno.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <stdbool.h>
# include <limits.h>

typedef struct s_file
{
	char	*file_name;
	int		redir_type;
	struct s_file	*next;
}			t_file;

typedef struct s_cmd
{
	char	*cmd_name;
	char	**cmd_args;
	int		cmd_type;
	int		cmd_position;
	struct s_file	*file;
	int		infilefd;
	int		outfilefd;
	int		last_pipe_read_end;
	int		pipe[2];
	struct s_cmd	*next;
	struct s_cmd	*prev;
}			t_cmd;

typedef struct s_data
{
	int		exit_status;
	int		shell_level;
	t_cmd	*cmd_list;
}			t_data;

#endif