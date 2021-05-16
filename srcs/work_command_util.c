#include "minishell.h"

int	is_builtin(t_cmd *cmd)
{
	if (cmd->cmd != 0)
	{
		if (ft_strcmp(cmd->cmd, "echo") == 0 || ft_strcmp(cmd->cmd, "cd") == 0
			|| ft_strcmp(cmd->cmd, "export") == 0
			|| ft_strcmp(cmd->cmd, "unset") == 0
			|| ft_strcmp(cmd->cmd, "exit") == 0
			|| ft_strcmp(cmd->cmd, "pwd") == 0
			|| ft_strcmp(cmd->cmd, "env") == 0)
			return (1);
		else
			return (0);
	}
	return (0);
}

void	check_fd(t_cmd *cmd)
{
	if (cmd->fd_out != 1)
	{
		close(cmd->fd_out);
		cmd->fd_out = 1;
	}
	if (cmd->fd_in != 0)
	{
		close(cmd->fd_in);
		cmd->fd_in = 0;
	}
}

void	find_cmd(t_all *all, t_cmd *cmd)
{
	if (cmd->pipe)
		cmd->fd_out = cmd->fds[1];
	if (ft_strcmp(cmd->cmd, "echo") == 0)
		my_echo(cmd->args + 1, cmd->fd_out);
	else if (ft_strcmp(cmd->cmd, "cd") == 0)
		cd(all, cmd->args);
	else if (ft_strcmp(cmd->cmd, "export") == 0)
		export(all, cmd->args, cmd->fd_out);
	else if (ft_strcmp(cmd->cmd, "unset") == 0)
		my_unset(all, cmd->args + 1);
	else if (ft_strcmp(cmd->cmd, "pwd") == 0)
		pwd(cmd->fd_out);
	else if (ft_strcmp(cmd->cmd, "env") == 0)
		env(all->env, cmd->fd_out);
	else if (ft_strcmp(cmd->cmd, "exit") == 0)
		ft_exit(all, cmd->args + 1);
	check_fd(cmd);
}

void	free_cmd(t_cmd *cmd)
{
	int	i;

	i = 0;
	while (cmd->args[i])
	{
		free(cmd->args[i]);
		cmd->args[i] = 0;
		i++;
	}
	free(cmd->args);
	free(cmd->cmd);
	cmd->cmd = 0;
}

int	parse_args(t_all *all, t_cmd *cmd, char **args)
{
	(void)cmd;
	(void)args;
	all->args = parse_dollars(all, all->args);
	if (!all->args)
		return (0);
	if (!(parse_redirect(all, all->args, cmd)))
		return (0);
	if (!(parse_pipes(all, all->args, cmd)))
		return (0);
	return (1);
}
