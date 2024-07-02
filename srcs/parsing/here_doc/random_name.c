/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   random_name.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsalomon <fsalomon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 16:58:05 by fsalomon          #+#    #+#             */
/*   Updated: 2024/07/02 17:48:04 by fsalomon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../headers/minishell.h"
#include "../../../headers/parsing.h"

static unsigned long	get_time_in_ms(void)
{
	struct timeval	time;
	unsigned long	time_stamp;

	gettimeofday(&time, NULL);
	time_stamp = (time.tv_sec * 1000) + (time.tv_usec * 0.001);
	return (time_stamp);
}

static char	*get_random_name(void)
{
	char			*file_name;
	unsigned long	time_in_ms;

	time_in_ms = get_time_in_ms();
	file_name = ft_itoa(time_in_ms);
	while (access(file_name, F_OK) == 0)
	{
		time_in_ms = get_time_in_ms();
		free(file_name);
		file_name = ft_itoa(time_in_ms);
	}
	return (file_name);
}

int	create_heredoc_file(t_redir_file *here_doc)
{
	int	fd;
	
	here_doc->file_name = get_random_name();
	printf("OPEN\n");
	fd = open(here_doc->file_name, O_WRONLY | O_APPEND | O_CREAT | 00644);
	return (fd);
}
