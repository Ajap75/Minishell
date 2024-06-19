#include "../headers/minishell.h"

void	ft_init_data(t_data *minishell)
{
	minishell->shell_level = 1;
	minishell->exit_status = 0;
	minishell->cmd_list = NULL;
}

int main (int argc, char **argv, char *envp[])
{
	t_data	minishell;

	ft_init_data(&minishell);
	(void)argc;
	(void)argv;
	(void)envp;
	return (1);
}