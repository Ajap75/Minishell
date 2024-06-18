/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsalomon <fsalomon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 11:13:09 by anastruc          #+#    #+#             */
/*   Updated: 2024/06/18 16:51:43 by fsalomon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/minishell.h"

int ft_pwd()
{

	if(getcwd(NULL, 0) == NULL)
		return (1);
	else
	{
		printf("%s\n", getcwd(NULL, 0));
		return (0);
	}
}

// int main (int argc, char **argv)
// {
//     if (argc >= 2)
//     {
//         if (strcmp(argv[1], "pwd") == 0)
//         {
//             printf("BUILT_IN PWD is called\n");
//             return(ft_pwd());
//         }
//     }
//     else
//         return(1);
// }