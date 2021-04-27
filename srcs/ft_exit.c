#include "minishell.h"

void	ft_exit(t_all *all, char **args)
{
	int i;

	i = 0;
	while (args[i])
		i++;
	if (i == 1)
	{
		/*printf("%s\n", args[0]);*/
		all->exit_status = ft_atoi(args[0]);
		exit(all->exit_status);
	}
	else
	{
		ft_putendl_fd("exit", 2);
		ft_putendl_fd("🚀: exit: too many arguments", 2);
	}
}
