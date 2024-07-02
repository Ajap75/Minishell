/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anastruc <anastruc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 14:21:29 by fsalomon          #+#    #+#             */
/*   Updated: 2024/07/02 18:01:54 by anastruc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# ifndef _POSIX_C_SOURCE
#  define _POSIX_C_SOURCE 199309L
# endif
# ifndef _DEFAULT_SOURCE
#  define _DEFAULT_SOURCE
# endif

# include "../libft/libft.h"
# include "built_in.h"
# include <errno.h>
# include <fcntl.h>
# include <limits.h>
# include <readline/history.h>
# include <readline/readline.h>
# include <signal.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/wait.h>
# include <unistd.h>

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
# define NONE_CMD 1024
# define CMD_NOT_FOUND 2048
# define NO_SUCH_FILE 4096
# define PERMISSION_DENIED 8192

typedef struct s_redir_file
{
	char				*file_name;
	int					redir_type;
	struct s_redir_file	*next;
}						t_redir_file;

typedef struct s_cmd
{
	char				*cmd_name;
	char				**cmd_args;
	int					cmd_type;
	int					cmd_pos;
	char				*cmd_path;
	t_redir_file		*file_in;
	t_redir_file		*file_out;
	int					infilefd;
	int					outfilefd;
	int					last_pipe_read_end;
	int					pipe[2];
	struct s_cmd		*next;
	struct s_cmd		*prev;
}						t_cmd;

typedef struct s_env
{
	char				*var_name;
	char				*var_value;
	struct s_env		*prev;
	struct s_env		*next;
}						t_env;

typedef struct s_data
{
	int					exit_status;
	t_cmd				*cmd_list;
	t_env				*env;
	char				**envp;
}						t_data;

// BUILT IN
int						ft_exit(char **args, t_data *data);

// TEST
void					unit_test(t_data *minishell);
void					print_cmd_lst(t_cmd *node);
void					print_cmd_node(t_cmd *node);

// Get_env
t_env					*get_env(char *envp[]);
void					lst_env_clear(t_env *lst_env);
void					ft_lstenvadd_back(t_env **env_lst, t_env *new_node);
t_env					*create_new_node(int j, char *envp, int partial);
void					print_env_lst(t_env *node);

// lst_redir_file
void					lst_redir_file_addback(t_redir_file **file_lst,
							t_redir_file *new_node);
void					lst_redir_file_clear(t_redir_file *file_lst);
t_redir_file			*init_node_lst_file(int redirtype, char *filename);
void					print_redir_file_lst(t_redir_file *node);

// DATA
t_data					*get_data(void);

// INIT
void					ft_init_data(char *envp[]);

// MALLOC ERROR
void					clean_all(void);

void					malloc_error(void);
void					malloc_error_env(t_env *lst_env, int fd);

// LST CMD
void					lst_cmd_clear(t_cmd *cmd_list);
void					lst_cmd_addback(t_cmd **cmd_list, t_cmd *new_node);
t_cmd					*lst_cmd_last(t_cmd *cmd_list);
t_cmd					*lst_cmd_new_node(void);

// SIGNAL

void					listen_signal(void);
void					signal_handler(int signum);
// EXEC
void					init_data_for_test_antoine(void);
void					execution(t_data *minishell);
void					child_process(t_cmd *cmd);
void					exec_cmd(t_cmd *cmd);
void					wait_for_children_to_end(t_data *minishell);
void					close_fd(t_cmd *cmd);
void					find_cmd_path(t_cmd *cmd, t_data *minishell);
char					*create_path(char *s1, char *s2, char *s3);
void	clean_parent_fd_and_set_last_pipe_read_end(t_cmd *cmd);


// PIPE_REDIR
void					last_cmd_case_pipe_redirection(t_cmd *cmd);
void					between_cmd_case_pipe_redirection(t_cmd *cmd);
void					first_cmd_case_pipe_redirection(t_cmd *cmd);
void					pipe_redirection_O_O_CMD_case(t_cmd *cmd);
void					pipe_redirection(t_cmd *cmd);
void					only_one_cmd_case_pipe_redirection(t_cmd *cmd);

// OPERAND_REDIR
void					operand_redirection(t_cmd *cmd);
void					check_operand_file(t_cmd *cmd);
void					check_file_in(t_cmd *cmd);
void					check_file_out(t_cmd *cmd);
void					file_in_unexisting_or_access_denied(t_redir_file *tmp_file_in,
							t_cmd *cmd);
void					file_in_existing(t_redir_file *tmp_file_in, t_cmd *cmd);
void					file_in_unexisting_or_access_denied(t_redir_file *tmp_file_in,
							t_cmd *cmd);
void					file_out_existing(t_redir_file *tmp_file_out,
							t_cmd *cmd);

// CHECK_FILE
void					file_out_unexisting_or_access_denied(t_redir_file *tmp_file_out,
							t_cmd *cmd);
void					file_out_exist(t_redir_file *tmp_file_out, t_cmd *cmd);

// ERR_MSG
int						err_msg(int err_type, char *msg);

#endif