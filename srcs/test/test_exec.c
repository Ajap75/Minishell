/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_exec.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anastruc <anastruc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 12:15:39 by fsalomon          #+#    #+#             */
/*   Updated: 2024/07/04 17:29:09 by anastruc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/minishell.h"

// PLUSIEURS PROBLEME DANS L"INITIALISATION POUR LES TESTE: POUR LE TABLEAU DE CHAINE DE CARACTER< IL FAUT INITIALISER LE DERNIER POINTEUR A NULL. POUR L"ECRITURE DE LA CHAINE
// DE CARACTERE QUI COMPRENDS LE NOM DE LA COMMANDE,
// IL NE FAUT PAS ECRASER l"ADRESSE PRECEDEMMENT MALLOC EN LA REMPLACANT PAR UNE CHAINE LITTERAL CAR 1) PERTE DE l"ESPACE PRECEDEMENT MALLOC.
// 2) INVALID FREE LORS DE LA LIBERATION DE LA MEMOIRE CAR TENTATIVE DE FREE UNE ZONE MEMOIRE NON ALLOUEE DYNAMIQUEMENT.
// 3) SOLUTION : UTILISER STRCOPY AVEC EN ARGUMENT LA ZONE MEMOIRE ET LA STRING A METTRE DANS CETTE ZONE.
//	4) Pareil pour cmd_name
//  7 fonctions pour initialiser la strucuture data de maniere a simuler 7 lines de commande differente

// 1) echo "Your PATH is $PATH"

void	init_data_for_test_line_1(t_data *minishell)
{
	minishell->cmd_list = lst_cmd_new_node();
	minishell->cmd_list->cmd_name = malloc(sizeof(char) * (5 + 1));
	minishell->cmd_list->cmd_name = "echo\0";
	minishell->cmd_list->cmd_args = malloc(sizeof(char *));
	minishell->cmd_list->cmd_args[0] = malloc(sizeof(char) * (5 + 1));
	minishell->cmd_list->cmd_args[0] = "echo\0";
	minishell->cmd_list->cmd_args[1] = malloc(sizeof(char)
			* (strlen("Your PATH is/home/fsalomon/.local/funcheck/host:/home/fsalomon/.local/bin:/home/fsalomon/bin:/home/fsalomon/.local/funcheck/host:/home/fsalomon/.local/bin:/home/fsalomon/bin:/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin:/usr/games:/usr/local/games:/snap/bin")
				+ 1));
	ft_strlcpy(minishell->cmd_list->cmd_args[1],
		"Your PATH is/home/fsalomon/.local/funcheck/host:/home/fsalomon/.local/bin:/home/fsalomon/bin:/home/fsalomon/.local/funcheck/host:/home/fsalomon/.local/bin:/home/fsalomon/bin:/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin:/usr/games:/usr/local/games:/snap/bin",
		strlen("Your PATH is/home/fsalomon/.local/funcheck/host:/home/fsalomon/.local/bin:/home/fsalomon/bin:/home/fsalomon/.local/funcheck/host:/home/fsalomon/.local/bin:/home/fsalomon/bin:/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin:/usr/games:/usr/local/games:/snap/bin")
		+ 1);
	minishell->cmd_list->cmd_args[1] = NULL;
	minishell->cmd_list->cmd_pos = ONLY_ONE_CMD;
	minishell->cmd_list->cmd_type = CMD;
}

// 2)  cat < input.txt | grep "something" | sort > output.txt
// pour tester cette line creer un fichier input.txt mettre pleins de ligne random dont certaines contiennent le mot something

t_data	*init_data_for_test_line_2(t_data *minishell)
{
	t_cmd	*cursor;

	minishell->cmd_list = lst_cmd_new_node();
	minishell->cmd_list->cmd_name = malloc(sizeof(char) * (ft_strlen("cat")
				+ 1));
	ft_strlcpy(minishell->cmd_list->cmd_name, "cat", 4);
	minishell->cmd_list->cmd_args = malloc(sizeof(char *) * 2);
	minishell->cmd_list->cmd_args[0] = malloc(sizeof(char) * (ft_strlen("cat")
				+ 1));
	ft_strlcpy(minishell->cmd_list->cmd_args[0], "cat", 4);
	minishell->cmd_list->cmd_args[1] = NULL;
	minishell->cmd_list->cmd_pos = FIRST_CMD;
	minishell->cmd_list->cmd_type = CMD;
	minishell->cmd_list->file_in = init_node_lst_file(SRC_REDIR, "input.txt");
	cursor = lst_cmd_new_node();
	cursor->cmd_name = malloc(sizeof(char) * (ft_strlen("grep") + 1));
	ft_strlcpy(cursor->cmd_name, "grep", 5);
	cursor->cmd_args = malloc(sizeof(char *) * 3);
	cursor->cmd_args[0] = malloc(sizeof(char) * (ft_strlen("grep") + 1));
	ft_strlcpy(cursor->cmd_args[0], "grep", 5);
	cursor->cmd_args[1] = malloc(sizeof(char) * (ft_strlen("something") + 1));
	ft_strlcpy(cursor->cmd_args[1], "something", 10);
	cursor->cmd_args[2] = NULL;
	cursor->cmd_pos = BETWEEN_CMD;
	cursor->cmd_type = CMD;
	lst_cmd_addback(&(minishell->cmd_list), cursor);
	cursor = lst_cmd_new_node();
	cursor->cmd_name = malloc(sizeof(char) * (ft_strlen("sort") + 1));
	ft_strlcpy(cursor->cmd_name, "sort", 5);
	cursor->cmd_args = malloc(sizeof(char *) * 2);
	cursor->cmd_args[0] = malloc(sizeof(char) * (ft_strlen("sort") + 1));
	ft_strlcpy(cursor->cmd_args[0], "sort", 5);
	cursor->cmd_args[1] = NULL;
	cursor->cmd_pos = LAST_CMD;
	cursor->cmd_type = CMD;
	cursor->file_out = init_node_lst_file(DST_REDIR, "output.txt");
	lst_cmd_addback(&(minishell->cmd_list), cursor);
	return (minishell);
}

// 3) << DEL
// pour tester cette line touch un fichier "random_156123" pour tester le fait de l'unlink

t_data	*init_data_for_test_line_3(t_data *minishell)
{
	minishell->cmd_list = lst_cmd_new_node();
	minishell->cmd_list->cmd_type = NO_CMD;
	minishell->cmd_list->file_in = init_node_lst_file(HERE_DOC,
			"random_156123");
	return (minishell);
}
// 4)>          file1
//
t_data	*init_data_for_test_line_4(t_data *minishell)
{
	minishell->cmd_list = lst_cmd_new_node();
	minishell->cmd_list->cmd_type = NO_CMD;
	minishell->cmd_list->file_in = init_node_lst_file(DST_REDIR, "file1");
	return (minishell);
}

// 5)< file1 cat | grep 'e' | rev > outfile1 > outfile2 >> outfile3

t_data	*init_data_for_test_line_5(t_data *minishell)
{
	t_cmd	*cursor;

	minishell->cmd_list = lst_cmd_new_node();
	minishell->cmd_list->cmd_name = malloc(sizeof(char) * (ft_strlen("cat")
				+ 1));
	minishell->cmd_list->cmd_name = "cat";
	minishell->cmd_list->cmd_args = malloc(sizeof(char *));
	minishell->cmd_list->cmd_args[0] = malloc(sizeof(char) * (ft_strlen("cat")
				+ 1));
	minishell->cmd_list->cmd_args[0] = "cat";
	minishell->cmd_list->cmd_pos = FIRST_CMD;
	minishell->cmd_list->cmd_type = CMD;
	minishell->cmd_list->file_in = init_node_lst_file(SRC_REDIR, "file1");
	cursor = lst_cmd_new_node();
	cursor->cmd_name = malloc(sizeof(char) * (ft_strlen("grep") + 1));
	cursor->cmd_name = "grep";
	cursor->cmd_args = malloc(sizeof(char *));
	cursor->cmd_args[0] = malloc(sizeof(char) * (ft_strlen("grep") + 1));
	cursor->cmd_args[0] = "grep";
	cursor->cmd_args[1] = malloc(sizeof(char) * (ft_strlen("e") + 1));
	cursor->cmd_args[1] = "e";
	cursor->cmd_pos = BETWEEN_CMD;
	cursor->cmd_type = CMD;
	lst_cmd_addback(&(minishell->cmd_list), cursor);
	cursor = lst_cmd_new_node();
	cursor->cmd_name = malloc(sizeof(char) * (ft_strlen("rev") + 1));
	cursor->cmd_name = "rev";
	cursor->cmd_args = malloc(sizeof(char *));
	cursor->cmd_args[0] = malloc(sizeof(char) * (ft_strlen("rev") + 1));
	cursor->cmd_args[0] = "rev";
	cursor->cmd_pos = LAST_CMD;
	cursor->cmd_type = CMD;
	cursor->file_out = init_node_lst_file(DST_REDIR, "outfile1");
	lst_redir_file_addback(&cursor->file_out, init_node_lst_file(DST_REDIR,
			"outfile2"));
	lst_redir_file_addback(&cursor->file_out, init_node_lst_file(APPEND,
			"outfile3"));
	lst_cmd_addback(&(minishell->cmd_list), cursor);
	return (minishell);
}

// 6) << DEL cat | grep $USER > outfile | < outfile rev | cat
//) pour tester cette ligne touch un fichier "random_51154"

t_data	*init_data_for_test_line_6(t_data *minishell)
{
	t_cmd	*cursor;

	minishell->cmd_list = lst_cmd_new_node();
	minishell->cmd_list->cmd_name = malloc(sizeof(char) * (ft_strlen("cat")
				+ 1));
	minishell->cmd_list->cmd_name = "cat";
	minishell->cmd_list->cmd_args = malloc(sizeof(char *));
	minishell->cmd_list->cmd_args[0] = malloc(sizeof(char) * (ft_strlen("cat")
				+ 1));
	minishell->cmd_list->cmd_args[0] = "cat";
	minishell->cmd_list->cmd_pos = FIRST_CMD;
	minishell->cmd_list->cmd_type = CMD;
	minishell->cmd_list->file_in = init_node_lst_file(HERE_DOC, "random_51154");
	cursor = lst_cmd_new_node();
	cursor->cmd_name = malloc(sizeof(char) * (ft_strlen("grep") + 1));
	cursor->cmd_name = "grep";
	cursor->cmd_args = malloc(sizeof(char *));
	cursor->cmd_args[0] = malloc(sizeof(char) * (ft_strlen("grep") + 1));
	cursor->cmd_args[0] = "grep";
	cursor->cmd_args[1] = malloc(sizeof(char) * (ft_strlen("fsalomon") + 1));
	cursor->cmd_args[1] = "fsalomon";
	cursor->cmd_pos = BETWEEN_CMD;
	cursor->cmd_type = CMD;
	cursor->file_out = init_node_lst_file(DST_REDIR, "outfile");
	lst_cmd_addback(&(minishell->cmd_list), cursor);
	cursor = lst_cmd_new_node();
	cursor->cmd_name = malloc(sizeof(char) * (ft_strlen("rev") + 1));
	cursor->cmd_name = "rev";
	cursor->cmd_args = malloc(sizeof(char *));
	cursor->cmd_args[0] = malloc(sizeof(char) * (ft_strlen("rev") + 1));
	cursor->cmd_args[0] = "rev";
	cursor->cmd_pos = BETWEEN_CMD;
	cursor->cmd_type = CMD;
	cursor->file_in = init_node_lst_file(SRC_REDIR, "outfile");
	lst_cmd_addback(&(minishell->cmd_list), cursor);
	cursor = lst_cmd_new_node();
	cursor->cmd_name = malloc(sizeof(char) * (ft_strlen("cat") + 1));
	cursor->cmd_name = "cat";
	cursor->cmd_args = malloc(sizeof(char *));
	cursor->cmd_args[0] = malloc(sizeof(char) * (ft_strlen("cat") + 1));
	cursor->cmd_args[0] = "cat";
	cursor->cmd_pos = LAST_CMD;
	cursor->cmd_type = CMD;
	lst_cmd_addback(&(minishell->cmd_list), cursor);
	return (minishell);
}

// 7) ls|grep e>outfile

t_data	*init_data_for_test_line_7(t_data *minishell)
{
	t_cmd	*cursor;

	minishell->cmd_list = lst_cmd_new_node();
	minishell->cmd_list->cmd_name = malloc(sizeof(char) * (ft_strlen("ls")
				+ 1));
	minishell->cmd_list->cmd_name = "ls";
	minishell->cmd_list->cmd_args = malloc(sizeof(char *));
	minishell->cmd_list->cmd_args[0] = malloc(sizeof(char) * (ft_strlen("ls")
				+ 1));
	minishell->cmd_list->cmd_args[0] = "ls";
	minishell->cmd_list->cmd_pos = FIRST_CMD;
	minishell->cmd_list->cmd_type = CMD;
	cursor = lst_cmd_new_node();
	cursor->cmd_name = malloc(sizeof(char) * (ft_strlen("grep") + 1));
	cursor->cmd_name = "grep";
	cursor->cmd_args = malloc(sizeof(char *));
	cursor->cmd_args[0] = malloc(sizeof(char) * (ft_strlen("grep") + 1));
	cursor->cmd_args[0] = "grep";
	cursor->cmd_args[1] = malloc(sizeof(char) * (ft_strlen("e") + 1));
	cursor->cmd_args[1] = "e";
	cursor->cmd_pos = LAST_CMD;
	cursor->cmd_type = CMD;
	cursor->file_out = init_node_lst_file(DST_REDIR, "outfile");
	lst_cmd_addback(&(minishell->cmd_list), cursor);
	return (minishell);
}
// int	main(int argc, char **argv, char *envp[])
// {
// 	(void)argv;
// 	(void)argc;
// 	t_data *minishell;

// 	minishell = get_data();
// 	ft_init_data(envp);
// 	init_data_for_test_line_7();
// 	print_cmd_lst(minishell->cmd_list);
// 	return (1);
// }

void	init_data_for_test_line_8(t_data *minishell)
{
	// t_cmd *cursor;

	minishell->cmd_list = lst_cmd_new_node();
	minishell->cmd_list->cmd_name = malloc(sizeof(char) * (ft_strlen("cd")
				+ 1));
	ft_strlcpy(minishell->cmd_list->cmd_name, "cd", 3);
	minishell->cmd_list->cmd_args = malloc(sizeof(char *) * 2);
	minishell->cmd_list->cmd_args[0] = malloc(sizeof(char) * (ft_strlen("cd")
				+ 1));
	ft_strlcpy(minishell->cmd_list->cmd_args[0], "cd", 3);
	minishell->cmd_list->cmd_args[1] = NULL;
	minishell->cmd_list->cmd_type = BUILT_IN;
	// cursor = lst_cmd_new_node();
	// cursor->cmd_name = malloc(sizeof(char) * (ft_strlen("grep") + 1));
	// cursor->cmd_name = "grep";
	// cursor->cmd_args = malloc(sizeof(char *));
	// cursor->cmd_args[0] = malloc(sizeof(char) * (ft_strlen("grep") + 1));
	// cursor->cmd_args[0] = "grep";
	// cursor->cmd_args[1] = malloc(sizeof(char) * (ft_strlen("e") + 1));
	// cursor->cmd_args[1] = "e";
	// cursor->cmd_pos = LAST_CMD;
	// cursor->cmd_type = CMD;
	// cursor->file_out = init_node_lst_file(DST_REDIR, "outfile");
	// lst_cmd_addback(&(minishell->cmd_list), cursor);
	return ;

}