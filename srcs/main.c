#include "../headers/minishell.h"

void	ft_init_data(t_data *minishell, char *envp[])
{
	minishell->shell_level = 1;
	minishell->exit_status = 0;
	minishell->cmd_list = NULL;
	minishell->envp = envp;
}


int	main(int argc, char **argv, char *envp[])
{
	t_data minishell;

	ft_init_data(&minishell, envp);
	unit_test(&minishell);
	(void)argc;
	(void)argv;
	return (1);
}