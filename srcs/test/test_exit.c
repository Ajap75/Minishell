#include "../../headers/minishell.h"
#include <assert.h>

void test_exit(t_data *minishell)
{
	char	*args[] = {"programme_name", "5468", "1354"};
	char	*args_1[] = {"programme_name", "9223372036854775808", NULL};
	char	*args_2[] = {"programme_name", "0", NULL};
	char	*args_3[] = {"programme_name", "9223372036854775807", NULL};
	char	*args_4[] = {"programme_name", "1", NULL};
	char	*args_5[] = {"programme_name", "2", NULL};
	char	*args_6[] = {"programme_name", "255", NULL};
	char	*args_7[] = {"programme_name", "256", NULL};
	char	*args_8[] = {"programme_name", "922337203685477580a", NULL};
	char	*args_9[] = {"programme_name", "a22337203685477580", NULL};
	char	**args_ptr;

	args_ptr = (char **)args;
	assert((ft_exit(args_ptr, minishell)) == 1);
	args_ptr = (char **)args_1;
	assert((ft_exit(args_ptr, minishell)) == 0);
	args_ptr = (char **)args_2;
	assert((ft_exit(args_ptr, minishell)) == 0);
	args_ptr = (char **)args_3;
	assert((ft_exit(args_ptr, minishell)) == 0);
	args_ptr = (char **)args_4;
	assert((ft_exit(args_ptr, minishell)) == 0);
	args_ptr = (char **)args_5;
	assert((ft_exit(args_ptr, minishell)) == 0);
	args_ptr = (char **)args_6;
	assert((ft_exit(args_ptr, minishell)) == 0);
	args_ptr = (char **)args_7;
	assert((ft_exit(args_ptr, minishell)) == 0);
	args_ptr = (char **)args_8;
	assert((ft_exit(args_ptr, minishell)) == 0);
	args_ptr = (char **)args_9;
	assert((ft_exit(args_ptr, minishell)) == 0);
}


// void	unit_test(t_data *minishell)
// {
// 	//assert((function_name(args)) == result attendu)
// 	// leak et previens si jamais les tests fails (resultat different) sinon renvoie le resultat
// 	test_exit(minishell);
// }
