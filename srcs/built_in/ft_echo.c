/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsalomon <fsalomon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 09:47:55 by anastruc          #+#    #+#             */
/*   Updated: 2024/06/18 16:51:07 by fsalomon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/minishell.h"
// struct t_cmd {


// t_file *file
// int infilefd;
// int outfilefd;
// int last_pipe_read_end;
// int cmd_type (Buitin, cmd)
// int cmd_position
//     char *cmd_name
//         char **cmd_args
// int pipe[2];
// int exit_status;
// t_cmd *next;
// t_cmd *prev;
//  };


// // int ft_init_t_cmd (struct *t_cmd)
// // {

// }

// IL FAUT INTEGRER UNE LIBFT, REMPLACER LES FONCTIONS INTERDITES //
// CREER UNE FONCTION QUI REMPLI LA STRUCUTRE POUR POUVOIR UTILISER LA STRUCTURE EN ARGUMENT DES BUILTIN //
// IL FAUDRA EGALEMENT GERER LES ERREURS EN CAS D"ECHEC D"EXECUTION //

int	ft_echo (char **cmd_args)
{
    int i;
    int noption;

    i = 0;
    while (cmd_args[i] != NULL)
    {
        if (strcmp(cmd_args[i], "-n") == 0)
            {
                noption = 1;
                i++;
                while (strcmp(cmd_args[i], "-n") == 0)
                    i++;
            }
    printf("%s", cmd_args[i]);
    if (cmd_args[i + 1] != NULL)
        printf(" ");
    i++;
    }
    if (noption == 0)
        printf("\n");
    return (0);
}

// int main (int argc, char **argv)
// {
//     if (argc >= 2)
//     {
//         if (strcmp(argv[1], "echo") == 0)
//         {
//             printf("BUILT_IN ECHO is called\n");
//             argv++;
//             argv++;
//             printf("argv = %s\n", argv[0]);
//             return(ft_echo(argv));
//         }
//     }
//     else
//         return(1);
// }