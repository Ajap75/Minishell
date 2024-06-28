/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_exec.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsalomon <fsalomon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 12:15:39 by fsalomon          #+#    #+#             */
/*   Updated: 2024/06/28 14:45:05 by fsalomon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/minishell.h"


//1) echo "Your PATH is $PATH"

void	init_data_for_test_line_1(void)
{
	t_data	*minishell;

	minishell = get_data();
	minishell->cmd_list = lst_cmd_new_node();
	minishell->cmd_list->cmd_name = malloc(sizeof(char) * (5 + 1));
	minishell->cmd_list->cmd_name = "echo\0";
	minishell->cmd_list->cmd_args = malloc(sizeof(char *));
	minishell->cmd_list->cmd_args[0] = malloc(sizeof(char) * (5 + 1));
	minishell->cmd_list->cmd_args[0] = "echo\0";
	minishell->cmd_list->cmd_args[1] = malloc(sizeof(char)* (strlen("Your PATH is/home/fsalomon/.local/funcheck/host:/home/fsalomon/.local/bin:/home/fsalomon/bin:/home/fsalomon/.local/funcheck/host:/home/fsalomon/.local/bin:/home/fsalomon/bin:/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin:/usr/games:/usr/local/games:/snap/bin")+ 1));
	minishell->cmd_list->cmd_args[1] = "Your PATH is/home/fsalomon/.local/funcheck/host:/home/fsalomon/.local/bin:/home/fsalomon/bin:/home/fsalomon/.local/funcheck/host:/home/fsalomon/.local/bin:/home/fsalomon/bin:/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin:/usr/games:/usr/local/games:/snap/bin";
	minishell->cmd_list->cmd_type = ONLY_ONE_CMD;
}

//2)  cat < input.txt | grep "something" | sort > output.txt
//pour tester cette line creer un fichier input.txt mettre pleins de ligne random dont certaines contiennent le mot something

void	init_data_for_test_line_2(void)
{
	t_data	*minishell;
	t_cmd	*cursor;

	minishell = get_data();
	minishell->cmd_list = lst_cmd_new_node();
	minishell->cmd_list->cmd_name = malloc(sizeof(char)* (ft_strlen("cat") + 1));
	minishell->cmd_list->cmd_name = "cat";
		minishell->cmd_list->cmd_args = malloc(sizeof(char *));

	minishell->cmd_list->cmd_args[0] = malloc(sizeof(char)* (ft_strlen("cat") + 1));
	minishell->cmd_list->cmd_args[0] = "cat";
	minishell->cmd_list->cmd_type = FIRST_CMD;
	minishell->cmd_list->file_in = init_node_lst_file(SRC_REDIR, "input.txt");
	cursor = lst_cmd_new_node();
	cursor->cmd_name = malloc(sizeof(char)* (ft_strlen("grep") + 1));
	cursor->cmd_name = "grep";
	cursor->cmd_args = malloc(sizeof(char *));
	cursor->cmd_args[0] = malloc(sizeof(char)* (ft_strlen("grep") + 1));
	cursor->cmd_args[0] = "grep";
	cursor->cmd_args[1] = malloc(sizeof(char)* (ft_strlen("something") + 1));
	cursor->cmd_args[1] = "something";
	cursor->cmd_type = BETWEEN_CMD;
	lst_cmd_addback(&(minishell->cmd_list), cursor);
	cursor = lst_cmd_new_node();
	cursor->cmd_name = malloc(sizeof(char)* (ft_strlen("sort") + 1));
	cursor->cmd_name = "sort";
	cursor->cmd_args = malloc(sizeof(char *));
	cursor->cmd_args[0] = malloc(sizeof(char)* (ft_strlen("sort") + 1));
	cursor->cmd_args[0] = "sort";
	cursor->cmd_type = LAST_CMD;
	cursor->file_out = init_node_lst_file(DST_REDIR, "output.txt");
	lst_cmd_addback(&(minishell->cmd_list), cursor);
}

//3) << DEL
 // pour tester cette line touch un fichier "random_156123" pour tester le fait de l'unlink

void	init_data_for_test_line_3(void)
{
	t_data	*minishell;

	minishell = get_data();
	minishell->cmd_list = lst_cmd_new_node();
	minishell->cmd_list->cmd_type = NONE_CMD;
	minishell->cmd_list->file_in = init_node_lst_file(HERE_DOC, "random_156123");
}
//4)>          file1
// 
void	init_data_for_test_line_4(void)
{
	t_data	*minishell;

	minishell = get_data();
	minishell->cmd_list = lst_cmd_new_node();
	minishell->cmd_list->cmd_type = NONE_CMD;
	minishell->cmd_list->file_in = init_node_lst_file(DST_REDIR, "file1");
}

//5)< file1 cat | grep 'e' | rev > outfile1 > outfile2 >> outfile3

void	init_data_for_test_line_5(void)
{
	t_data	*minishell;
	t_cmd	*cursor;

	minishell = get_data();
	minishell->cmd_list = lst_cmd_new_node();
	minishell->cmd_list->cmd_name = malloc(sizeof(char)* (ft_strlen("cat") + 1));
	minishell->cmd_list->cmd_name = "cat";
	minishell->cmd_list->cmd_args = malloc(sizeof(char *));
	minishell->cmd_list->cmd_args[0] = malloc(sizeof(char)* (ft_strlen("cat") + 1));
	minishell->cmd_list->cmd_args[0] = "cat";
	minishell->cmd_list->cmd_type = FIRST_CMD;
	minishell->cmd_list->file_in = init_node_lst_file(SRC_REDIR, "file1");
	cursor = lst_cmd_new_node();
	cursor->cmd_name = malloc(sizeof(char)* (ft_strlen("grep") + 1));
	cursor->cmd_name = "grep";
	cursor->cmd_args = malloc(sizeof(char *));
	cursor->cmd_args[0] = malloc(sizeof(char)* (ft_strlen("grep") + 1));
	cursor->cmd_args[0] = "grep";
	cursor->cmd_args[1] = malloc(sizeof(char)* (ft_strlen("e") + 1));
	cursor->cmd_args[1] = "e";
	cursor->cmd_type = BETWEEN_CMD;
	lst_cmd_addback(&(minishell->cmd_list), cursor);
	cursor = lst_cmd_new_node();
	cursor->cmd_name = malloc(sizeof(char)* (ft_strlen("rev") + 1));
	cursor->cmd_name = "rev";
	cursor->cmd_args = malloc(sizeof(char *));
	cursor->cmd_args[0] = malloc(sizeof(char)* (ft_strlen("rev") + 1));
	cursor->cmd_args[0] = "rev";
	cursor->cmd_type = LAST_CMD;
	cursor->file_out = init_node_lst_file(DST_REDIR, "outfile1");
	lst_redir_file_addback(&cursor->file_out, init_node_lst_file(DST_REDIR, "outfile2"));
	lst_redir_file_addback(&cursor->file_out, init_node_lst_file(APPEND, "outfile3"));
	lst_cmd_addback(&(minishell->cmd_list), cursor);
}


//6) << DEL cat | grep $USER > outfile | < outfile rev | cat
//) pour tester cette ligne touch un fichier "random_51154"

void	init_data_for_test_line_6(void)
{
	t_data	*minishell;
	t_cmd	*cursor;

	minishell = get_data();
	minishell->cmd_list = lst_cmd_new_node();
	minishell->cmd_list->cmd_name = malloc(sizeof(char)* (ft_strlen("cat") + 1));
	minishell->cmd_list->cmd_name = "cat";
	minishell->cmd_list->cmd_args = malloc(sizeof(char *));
	minishell->cmd_list->cmd_args[0] = malloc(sizeof(char)* (ft_strlen("cat") + 1));
	minishell->cmd_list->cmd_args[0] = "cat";
	minishell->cmd_list->cmd_type = FIRST_CMD;
	minishell->cmd_list->file_in = init_node_lst_file(HERE_DOC, "random_51154");
	cursor = lst_cmd_new_node();
	cursor->cmd_name = malloc(sizeof(char)* (ft_strlen("grep") + 1));
	cursor->cmd_name = "grep";
	cursor->cmd_args = malloc(sizeof(char *));
	cursor->cmd_args[0] = malloc(sizeof(char)* (ft_strlen("grep") + 1));
	cursor->cmd_args[0] = "grep";
	cursor->cmd_args[1] = malloc(sizeof(char)* (ft_strlen("fsalomon") + 1));
	cursor->cmd_args[1] = "fsalomon";
	cursor->cmd_type = BETWEEN_CMD;
	cursor->file_out = init_node_lst_file(DST_REDIR, "outfile");
	lst_cmd_addback(&(minishell->cmd_list), cursor);
	cursor = lst_cmd_new_node();
	cursor->cmd_name = malloc(sizeof(char)* (ft_strlen("rev") + 1));
	cursor->cmd_name = "rev";
	cursor->cmd_args = malloc(sizeof(char *));
	cursor->cmd_args[0] = malloc(sizeof(char)* (ft_strlen("rev") + 1));
	cursor->cmd_args[0] = "rev";
	cursor->cmd_type = BETWEEN_CMD;
	cursor->file_in = init_node_lst_file(SRC_REDIR, "outfile");
	lst_cmd_addback(&(minishell->cmd_list), cursor);
	cursor = lst_cmd_new_node();
	cursor->cmd_name = malloc(sizeof(char)* (ft_strlen("cat") + 1));
	cursor->cmd_name = "cat";
	cursor->cmd_args = malloc(sizeof(char *));
	cursor->cmd_args[0] = malloc(sizeof(char)* (ft_strlen("cat") + 1));
	cursor->cmd_args[0] = "cat";
	cursor->cmd_type = LAST_CMD;
	lst_cmd_addback(&(minishell->cmd_list), cursor);
}


//7) ls|grep e>outfile

void	init_data_for_test_line_7(void)
{
	t_data	*minishell;
	t_cmd	*cursor;

	minishell = get_data();
	minishell->cmd_list = lst_cmd_new_node();
	minishell->cmd_list->cmd_name = malloc(sizeof(char)* (ft_strlen("ls") + 1));
	minishell->cmd_list->cmd_name = "ls";
	minishell->cmd_list->cmd_args = malloc(sizeof(char *));
	minishell->cmd_list->cmd_args[0] = malloc(sizeof(char)* (ft_strlen("ls") + 1));
	minishell->cmd_list->cmd_args[0] = "ls";
	minishell->cmd_list->cmd_type = FIRST_CMD;
	cursor = lst_cmd_new_node();
	cursor->cmd_name = malloc(sizeof(char)* (ft_strlen("grep") + 1));
	cursor->cmd_name = "grep";
	cursor->cmd_args = malloc(sizeof(char *));
	cursor->cmd_args[0] = malloc(sizeof(char)* (ft_strlen("grep") + 1));
	cursor->cmd_args[0] = "grep";
	cursor->cmd_args[1] = malloc(sizeof(char)* (ft_strlen("e") + 1));
	cursor->cmd_args[1] = "e";
	cursor->cmd_type = LAST_CMD;
	cursor->file_out = init_node_lst_file(DST_REDIR, "outfile");
	lst_cmd_addback(&(minishell->cmd_list), cursor);
}
int	main(int argc, char **argv, char *envp[])
{
	(void)argv;
	(void)argc;
	t_data *minishell;

	minishell = get_data();
	ft_init_data(envp);
	init_data_for_test_line_7();
	print_cmd_lst(minishell->cmd_list);
	return (1);
}