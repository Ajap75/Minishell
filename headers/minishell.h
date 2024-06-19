/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsalomon <fsalomon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 14:21:29 by fsalomon          #+#    #+#             */
/*   Updated: 2024/06/19 10:58:31 by fsalomon         ###   ########.fr       */
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
#include <readline/readline.h>
#include <readline/history.h>
# include "../libft/libft.h"
# include "built_in.h"

# define SIZE_MAX 	500
# define SRC_REDIR	1		1
# define DST_REDIR	2
# define APPEND		4
# define HERE_DOC 	8
# define BUILT_IN	16
# define CMD		32

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