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

char	*find_in_path(t_all *all, char *command)
{
	char	**path;
	int		i;
	char	*ret;

	i = -1;
	if (find_slesh(command))
	{
		ret = ft_strdup(command);
		return (ret);
	}
	path = ft_split(get_env(all, "PATH"), ':');
	if (!path)
		return (0);
	while (path[++i])
	{
		path[i] = ft_strjoin(path[i], "/");
		path[i] = ft_strjoin(path[i], command);
	}
	ret = search_path(path);
	free_split(path);
	return (ret);
}

void	bin_error(char *arg)
{
	ft_putstr_fd("🚀: ", 2);
	ft_putstr_fd(arg, 2);
	ft_putendl_fd(" : command not found", 2);
	return ;
}

void	exec_error(t_all *all, char *bin)
{
	ft_putstr_fd("🚀: ", 2);
	ft_putstr_fd(bin, 2);
	ft_putendl_fd(": No such file or directory", 2);
	all->exit_status = WEXITSTATUS(all->exit_status);
	exit(all->exit_status);
}

void	check_dochka(int exit_status)
{
	if (WIFSIGNALED(exit_status))
	{
		if (WTERMSIG(exit_status) == SIGQUIT)
			ft_putstr("Ouit: 3\n");
	}
}

void	my_execve(t_all *all, char **args, t_cmd *cmd)
{
	char	*bin;
	pid_t	pid;

	if (!cmd->cmd)
		return ;
	bin = find_in_path(all, args[0]);
	if (!bin)
		return (bin_error(args[0]));
	pid = fork();
	if (cmd->pipe)
		close(cmd->fds[0]);
	if (pid == 0)
	{
		if (cmd->pipe)
			dup2(cmd->fds[1] , 1);
		if (cmd->fd_out != 1)
			dup2(cmd->fd_out, 1);
		if (cmd->fd_in != 0)
			dup2(cmd->fd_in, 0);
		if (execve(bin, all->args, all->env) == -1)
			exec_error(all, bin);
	}
	signal(SIGQUIT, f);
	signal(SIGINT, f);
	waitpid(pid, &all->exit_status, 0);
	check_dochka(all->exit_status);
	signal(SIGQUIT, func);
	signal(SIGINT, sig_c);
	all->exit_status = WEXITSTATUS(all->exit_status);
	free(bin);
}
