#include "minishell.h"

int	count_pipes(char **args)
{
	int i;
	int res;

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

void	get_args_cmd_pipe(t_all *all, char **args)
{
	(void)all;
	int i;
	int j;

	i = 0;
	j = 0;
	while (args[i] && args[i][0] != '|')
		i++;

}

int parse_pipes(t_all *all, char **args, t_cmd *cmd)
{
	(void)all;
	(void)cmd;
	int n;

	n = count_pipes(args);
	for (int i = 0; all->args[i] != 0; i++)
		printf("%s\n", all->args[i]);
	/*printf("%d\n", n);*/
	if (n > 0)
	{
		cmd->pipe = n;
		pipe(cmd->fds);
		/*printf("%d\n", cmd->fds[0]);*/
		/*printf("%d\n", cmd->fds[1]);*/
	}
	get_args_cmd_pipe(all, args);
	return (1);
}
