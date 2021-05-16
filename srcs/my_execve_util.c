#include "minishell.h"

char	*get_env(t_all *all, char *line)
{
	int		index;
	int		i;
	char	*ret;

	i = -1;
	index = find_name(all, line) - 1;
	if (index != -1)
	{
		ret = all->env[index];
		while (all->env[index] && all->env[index][++i] != '=')
			ret++;
		return (++ret);
	}
	return (0);
}

char	*search_path(char **path)
{
	int			i;
	struct stat	buf;
	char		*ret;

	i = -1;
	while (path[++i])
	{
		if (stat(path[i], &buf) == 0)
		{
			ret = ft_strdup(path[i]);
			return (ret);
		}
	}
	return (0);
}

int	find_slesh(char *command)
{
	int	i;

	i = -1;
	while (command[++i])
	{
		if (command[i] == '/')
			return (1);
	}
	return (0);
}

void	dochka_work(t_cmd *cmd, char *bin, t_all *all)
{
	if (cmd->pipe)
		dup2(cmd->fds[1], 1);
	if (cmd->fd_out != 1)
		dup2(cmd->fd_out, 1);
	if (cmd->fd_in != 0)
		dup2(cmd->fd_in, 0);
	if (execve(bin, all->args, all->env) == -1)
		exec_error(all, bin);
}
