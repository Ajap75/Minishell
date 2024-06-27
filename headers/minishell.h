/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anastruc <anastruc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 14:21:29 by fsalomon          #+#    #+#             */
/*   Updated: 2024/06/27 17:14:41 by anastruc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "../libft/libft.h"
# include "built_in.h"
# include <errno.h>
# include <limits.h>
# include <readline/history.h>
# include <readline/readline.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <fcntl.h>

# define SIZE_MAX 500
# define SRC_REDIR 1
# define DST_REDIR 2
# define APPEND 4
# define HERE_DOC 8
# define BUILT_IN 16
# define CMD 32
# define FIRST_CMD 64
# define BETWEEN_CMD 128
# define LAST_CMD 256
# define ONLY_ONE_CMD 512

typedef struct s_redir_file
{
	char					*file_name;
	int						redir_type;
	struct s_redir_file		*next;
}							t_redir_file;

typedef struct s_cmd
{
	char					*cmd_name;
	char					**cmd_args;
	int						cmd_type;
	t_redir_file	*file_in;
	t_redir_file	*file_out;
	int						infilefd;
	int						outfilefd;
	int						last_pipe_read_end;
	int						pipe[2];
	struct s_cmd			*next;
	struct s_cmd			*prev;
}							t_cmd;

typedef struct s_env
{
	char					*var_name;
	char					*var_value;
	struct s_env			*prev;
	struct s_env			*next;
}							t_env;

typedef struct s_data
{
	int						exit_status;
	t_cmd					*cmd_list;
	t_env					*env;
}							t_data;

// TEST

void						unit_test(t_data *minishell);
int							ft_exit(char **args, t_data *data);
;

// Get_env
t_env	*get_env(char *envp[]);
void	lst_env_clear(t_env *lst_env);
void	ft_lstenvadd_back(t_env **env_lst, t_env *new_node);
t_env	*create_new_node(int j, char *envp, int partial);
void	print_env_lst(t_env *node);


// lst_redir_file

void	lst_redir_file_addback(t_redir_file **file_lst, t_redir_file *new_node);
void	lst_redir_file_clear(t_redir_file *file_lst);
t_redir_file	*init_node_lst_file(int redirtype, char *filename);
void	print_redir_file_lst(t_redir_file *node);


//DATA
t_data *get_data(void);


//INIT
t_data	*ft_init_data(char *envp[]);

//MALLOC ERROR
void		malloc_error(void);
void		malloc_error_env(t_env *lst_env, int fd);


//LST CMD
void	lst_cmd_clear(t_cmd *cmd_list);
void	lst_cmd_addback(t_cmd **cmd_list, t_cmd *new_node);
t_cmd	*lst_cmd_last(t_cmd *cmd_list);
t_cmd	*lst_cmd_new_node(void);


#endif