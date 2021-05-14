#include "minishell.h"

int	redirect_error(void)
{
	ft_putendl_fd("🚀: syntax error near unexpected token `newline'", 2);
	return (0);
}

int	count_files(char **args)
{
	int	i;
	int	res;

	i = 0;
	res = 0;
	while (args[i] && args[i][0] != ';')
	{
		if (ft_strcmp(args[i], ">>") == 0 || ft_strcmp(args[i], ">") == 0
			|| ft_strcmp(args[i], "<") == 0)
			res++;
		i++;
	}
	return (res);
}

void	fill_files(char **args, t_cmd *cmd)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (args[i] && args[i][0] != ';')
	{
		if (ft_strcmp(args[i], ">>") == 0)
		{
			cmd->files[j++] = ft_strdup(args[i + 1]);
		}
		else if (ft_strcmp(args[i], ">") == 0)
		{
			cmd->files[j++] = ft_strdup(args[i + 1]);
		}
		else if (ft_strcmp(args[i], "<") == 0)
		{
			cmd->files[j++] = ft_strdup(args[i + 1]);
		}
		i++;
	}
}

int	check_files(char **files, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		if (files[i] == 0)
			return (0);
		i++;
	}
	return (1);
}

int	error_fd(char *arg)
{
	ft_putstr_fd("🚀: ", 2);
	ft_putstr_fd(arg, 2);
	ft_putendl_fd(" : No such file or directory", 2);
	return (0);
}

int	open_files(char **args, t_cmd *cmd)
{
	int	i;

	i = 0;
	while (args[i] && args[i][0] != ';')
	{
		if (ft_strcmp(args[i], ">>") == 0 && args[i + 1] != 0)
			cmd->fd_out = open(args[i + 1], O_WRONLY | O_CREAT | O_APPEND,
					S_IWUSR | S_IRUSR);
		else if (ft_strcmp(args[i], ">") == 0 && args[i + 1] != 0)
			cmd->fd_out = open(args[i + 1], O_WRONLY | O_CREAT | O_TRUNC,
					S_IWUSR | S_IRUSR);
		else if (ft_strcmp(args[i], "<") == 0 && args[i + 1] != 0)
		{
			cmd->fd_in = open(args[i + 1], O_RDONLY);
			if (cmd->fd_in == -1)
			{
				return (error_fd(args[i + 1]));
			}
		}
		i++;
	}
	return (1);
}

void	copy_args_without_redirect(t_all *all, char **args, int i)
{
	int	j;
	char **p;

	p = malloc(sizeof(char *) * (i + 1));
	p[i] = 0;
	i = 0;
	j = 0;
	while (args[i] && args[i][0] != ';')
	{
		if (ft_strcmp(args[i], ">>") == 0 || ft_strcmp(args[i], ">") == 0
			|| ft_strcmp(args[i], "<") == 0)
		{
			i += 2;
			continue ;
		}
		p[j++] = ft_strdup(args[i]);
		i++;
	}
	free_split(all->args);
	all->args = p;
}

void	get_args_cmd(t_all *all, char **args)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (args[i] && args[i][0] != ';')
		i++;
	while (args[j] && args[j][0] != ';')
	{
		if (ft_strcmp(args[j], ">>") == 0 || ft_strcmp(args[j], ">") == 0
			|| ft_strcmp(args[j], "<") == 0)
			i -= 2;
		j++;
	}
	copy_args_without_redirect(all, args, i);
}

int	parse_redirect(t_all *all, char **args, t_cmd *cmd)
{
	int	n;
	int	i;

	i = 0;
	n = count_files(args);
	if (n > 0)
	{
		cmd->files = malloc(sizeof(char *) * (n + 1));
		cmd->files[n] = 0;
		fill_files(args, cmd);
		if (check_files(cmd->files, n) == 0)
			return (redirect_error());
		if (open_files(args, cmd) == 0)
			return (0);
		free_split(cmd->files);
	}
	get_args_cmd(all, args);
	return (1);
}
