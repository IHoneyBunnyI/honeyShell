#include "minishell.h"

void	get_args(char **args, t_cmd *cmd)
{
	int i;

	i = 0;
	if (!args)
		return ;
	while (args[i])
		i++;
	cmd->args = malloc(sizeof(char *) * (i + 1));
	cmd->args[i] = 0;
	i = 0;
	while (args[i])
	{
		if (cmd->cmd == 0 && args[i][0] != '-')
		{
			cmd->cmd = ft_strdup(args[i]);
			cmd->args[i] = ft_strdup(args[i]);
		}
		else if (cmd->cmd != 0 && args[i][0] == '-')
			cmd->args[i] = ft_strdup(args[i]);
		else if (cmd->cmd != 0 && args[i][0] != '-')
			cmd->args[i] = ft_strdup(args[i]);
		i++;
	}
}
