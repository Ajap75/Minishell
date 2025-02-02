/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anastruc <anastruc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 14:21:29 by fsalomon          #+#    #+#             */
/*   Updated: 2024/07/04 17:29:25 by anastruc         ###   ########.fr       */
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
# define NO_CMD 1024
# define CMD_NOT_FOUND 2048
# define NO_SUCH_FILE 4096
# define PERMISSION_DENIED 8192
# define CMD_NOT_EXECUTABLE 16384
# define DUP2_FAIL 32768
# define OPEN_FAIL 65536
# define PIPE_FAIL 131072
# define FORK_FAIL 262144
# define MALLOC_ERROR 524288
# define HOME_NOT_SET 1048576
# define CHDIR 2097152

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
int						ft_cd(t_cmd *cmd, t_data *minishell);

// TEST
void					unit_test(t_data *minishell);
void					print_cmd_lst(t_cmd *node);
void					print_cmd_node(t_cmd *node);
void					init_data_for_test_line_1(t_data *minishell);
t_data					*init_data_for_test_line_2(t_data *minishell);
t_data					*init_data_for_test_line_3(t_data *minishell);
t_data					*init_data_for_test_line_4(t_data *minishell);
void					init_data_for_test_line_8(t_data *minishell);
t_data					*init_data_for_test_line_5(t_data *minishell);

t_data					*init_data_for_test_line_6(t_data *minishell);

// Get_env
t_env					*get_env(char *envp[], t_data *minishell);
void					lst_env_clear(t_env *lst_env);
void					ft_lstenvadd_back(t_env **env_lst, t_env *new_node);
t_env					*create_new_node(int j, char *envp, int partial);
void					print_env_lst(t_env *node);
char					*get_next_line_and_init_envp(int fd);

// lst_redir_file
void					lst_redir_file_addback(t_redir_file **file_lst,
							t_redir_file *new_node);
void					lst_redir_file_clear(t_redir_file *file_lst);
t_redir_file			*init_node_lst_file(int redirtype, char *filename);
void					print_redir_file_lst(t_redir_file *node);

// DATA
t_data					*get_data(void);

// INIT
t_data					*ft_init_data(char *envp[], t_data *minishell);

// MALLOC ERROR
void					clean_all(t_data *minishell);

void					malloc_error(t_data *minishell);
void					malloc_error_env(t_env *lst_env, int fd,
							t_data *minishell);

// LST CMD
t_cmd					*lst_cmd_new_node(void);
void					lst_cmd_clear(t_cmd *cmd_list);
void					lst_cmd_addback(t_cmd **cmd_list, t_cmd *new_node);
t_cmd					*lst_cmd_last(t_cmd *cmd_list);
void					signal_handler(int signum);
// EXEC
void					init_data_for_test_antoine(t_data *minishell);
int						execution(t_data *minishell);
void					child_process(t_cmd *cmd, t_data *minishell);
void					exec_cmd(t_cmd *cmd, t_data *minishell);
void					exec_built_in(t_cmd *cmd, t_data *minishell);

int						wait_for_children_to_end(int exit_status);
void					close_fd(t_cmd *cmd);
void					find_cmd_path(t_cmd *cmd, t_data *minishell);
char					*create_path(char *s1, char *s2, char *s3);
void					clean_parent_fd_and_set_last_pipe_read_end(t_cmd *cmd);

// PIPE_REDIR
void					last_cmd_case_pipe_redirection(t_cmd *cmd,
							t_data *minishell);
void					between_cmd_case_pipe_redirection(t_cmd *cmd,
							t_data *minishell);
void					first_cmd_case_pipe_redirection(t_cmd *cmd,
							t_data *minishell);
void					pipe_redirection_O_O_CMD_case(t_cmd *cmd,
							t_data *minishell);
void					pipe_redirection(t_cmd *cmd, t_data *minishell);
void					only_one_cmd_case_pipe_redirection(t_cmd *cmd);

// OPERAND_REDIR
void					operand_redirection(t_cmd *cmd, t_data *minishell);
void					check_operand_file(t_cmd *cmd, t_data *minishell);
void					check_file_in(t_cmd *cmd, t_data *minishell);
void					check_file_out(t_cmd *cmd, t_data *minishell);
void					file_in_unexisting_or_access_denied(t_redir_file *tmp_file_in,
							t_cmd *cmd, t_data *minishell);
void					file_in_existing(t_redir_file *tmp_file_in, t_cmd *cmd,
							t_data *minishell);
void					file_in_unexisting_or_access_denied(t_redir_file *tmp_file_in,
							t_cmd *cmd, t_data *minishell);
void					file_out_existing(t_redir_file *tmp_file_out,
							t_cmd *cmd, t_data *minishell);

// CHECK_FILE
void					file_out_unexisting_or_access_denied(t_redir_file *tmp_file_out,
							t_cmd *cmd, t_data *minishell);
void					file_out_exist(t_redir_file *tmp_file_out, t_cmd *cmd,
							t_data *minishell);

// ERR_MSG
int						err_msg(int err_type, char *msg, t_cmd *cmd,
							t_data *minishell);

#endif