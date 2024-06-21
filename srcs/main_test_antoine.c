/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_test_antoine.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anastruc <anastruc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 15:22:08 by anastruc          #+#    #+#             */
/*   Updated: 2024/06/21 16:59:36 by anastruc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

int	main(int argc, char **argv)
{
	int	len;
	int	i;

	if (argc == 2)
	{
		len = ft_strlen(argv[1]);
		i = 0;

		while (argv[1][i] != '=' && argv[1][i])
			i++;
		printf("var name = %s\n", ft_substr(argv[1], 0, (i)));
		printf("var value = %s\n", ft_substr(argv[1], (len - i), len));
	}
	return (0);
}
