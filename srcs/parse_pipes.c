#include "minishell.h"

int	count_pipes(char **args)
{
	int	i;
	int	res;

	i = 0;
	res = 0;
	while (args[i])
	{
		if (args[i][0] == '|')
			res++;
		i++;
	}
	return (res);
}

int	parse_pipes(t_all *all, char **args, t_cmd *cmd)
{
	(void)all;
	(void)cmd;
	(void)args;
	if (cmd->pipe)
	{
		pipe(cmd->fds);
	}
	return (1);
}
