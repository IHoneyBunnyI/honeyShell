#include "minishell.h"

void	redirect_error(void)
{
	ft_putendl_fd("🚀: cd: syntax error near unexpected token `newline'", 2);
}

int	count_files(char **args)
{
	int	i;
	int	res;

	i = 0;
	res = 0;
	while (args[i] && args[i][0] != ';')
	{
		if (ft_strcmp(args[i], ">>") == 0 || ft_strcmp(args[i], ">") == 0)
			res++;
		i++;
	}
	return (res);
}

void	fill_files(char **args, t_cmd *cmd)
{
	int i;
	int j;

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

void	open_files(char **args, t_cmd *cmd)
{
	int	i;

	i = 0;
	while (args[i] && args[i][0] != ';')
	{
		if (ft_strcmp(args[i], ">>") == 0 && args[i + 1] != 0)
			cmd->fd = open(args[i + 1], O_WRONLY | O_CREAT | O_TRUNC, S_IWUSR | S_IRUSR);
		else if (ft_strcmp(args[i], ">") == 0 && args[i + 1] != 0)
			cmd->fd = open(args[i + 1], O_WRONLY | O_CREAT | O_APPEND, S_IWUSR | S_IRUSR);
		i++;
	}
}

void copy_args_without_redirect(t_all *all, char **args, int i)
{
	int j;

	all->args = malloc(sizeof(char *) * i + 1);
	all->args[i] = 0;
	i = 0;
	j = 0;
	while (args[i] && args[i][0] != ';')
	{
		if (ft_strcmp(args[i], ">>") == 0 || ft_strcmp(args[i], ">") == 0)
		{
			i += 2;
			continue ;
		}
		all->args[j++] = ft_strdup(args[i]);
		i++;
	}
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
		if (ft_strcmp(args[j], ">>") == 0 || ft_strcmp(args[j], ">") == 0)
			i -= 2;
		j++;
	}
	copy_args_without_redirect(all, args, i);
}

void	parse_redirect(t_all *all, char **args, t_cmd *cmd)
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
		open_files(args, cmd);
		free_split(cmd->files);
	}
	get_args_cmd(all, args);
}
