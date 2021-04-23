#include "minishell.h"

void	work_command(t_all *all, t_tokens *tkn)
{
	int	fd;

	fd = 1;
	all->args = convert_tkn(tkn);
	if (is_echo(all->args[0]))
		my_echo(all->args + 1);
	else if (all->args[0][0] == 'e' && all->args[0][1] == 'n' && all->args[0][2] == 'v')
		env(all->env, fd);
	else if (all->args[0][0] == 'p' && all->args[0][1] == 'w' && all->args[0][2] == 'd')
		pwd(fd);
	else if (all->args[0][0] == 'e' && all->args[0][1] == 'x' && all->args[0][2] == 'p' && \
			 all->args[0][3] == 'o' && all->args[0][4] == 'r' && all->args[0][5] == 't' )
		export(all, all->args, fd);
	else if (all->args[0][0] == 'u' && all->args[0][1] == 'n' && all->args[0][2] == 's' && \
			 all->args[0][3] == 'e' && all->args[0][4] == 't')
		my_unset(all, all->args + 1);
	else if (all->args[0][0] == 'c' && all->args[0][1] == 'd')
		cd(all, all->args);
	else if (all->args[0][0] == 'e' && all->args[0][1] == 'x' && all->args[0][2] == 'i' && all->args[0][3] == 't')
		ft_exit(all->args);
	else if (ft_strcmp(all->args[0], "") != 0)
		my_execve(all, all->args, fd);
	free_split(all->args);
}
