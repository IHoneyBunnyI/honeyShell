#include "minishell.h"

void	get_args(char **args, t_cmd *cmd)
{
	int i;

	i = 0;
	if (cmd->cmd == 0 && args[i][0] != '-')
		;
	i = 0;
	while (args[i])
	{
		printf("%s\n", args[i]);
		i++;
	}
}
