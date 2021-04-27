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

char	*find_in_path(t_all *all, char *command)
{
	char	**path;
	int		i;
	char	*ret;

	i = -1;
	if (ft_strcmp(command, "./minishell") == 0)
	{
		ret = ft_strdup("./minishell");
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

void	my_execve(t_all *all, char **args, int fd)
{
	char	*bin;
	pid_t	pid;
	int		angelina;


	bin = find_in_path(all, args[0]);
	if (!bin)
	{
		ft_putstr_fd("🚀: ", 2);
		ft_putstr_fd(args[0], 2);
		ft_putendl_fd(" : command not found", 2);
		return ;
	}
	pid = fork();
	if (pid == 0)
	{
		dup2(fd, 1);
		execve(bin, all->args, all->env);
	}
	signal(SIGQUIT, f);
	signal(SIGINT, f);
	waitpid(pid, &angelina, 0);
	if (WIFSIGNALED(angelina))
	{
		if (WTERMSIG(angelina) == SIGQUIT)
			ft_putstr("Ouit: 3\n");
	}
	signal(SIGQUIT, func);
	signal(SIGINT, sig_c);
	free(bin);
}
