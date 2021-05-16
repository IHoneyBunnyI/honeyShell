#include "minishell.h"

void	if_pid_o(t_cmd *cmd)
{
	cmd->pipe = 0;
	cmd->pipe_in = 1;
	dup2(cmd->fds[0], 0);
	close(cmd->fds[1]);
	free_cmd(cmd);
}
