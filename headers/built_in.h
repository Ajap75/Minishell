/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_in.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsalomon <fsalomon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 16:57:35 by fsalomon          #+#    #+#             */
/*   Updated: 2024/06/19 11:46:25 by fsalomon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILT_IN_H
# define BUILT_IN_H

# include "minishell.h"
# include <stdbool.h>
// EXIT

bool	ft_atoll(const char *arg, long long *arg_exit);
int		it_is_only_digit(char *arg);
int		there_is_an_overflow(char *arg, long long *arg_exit);
void	ft_print_exit_error(int error_num, char *args);


#endif