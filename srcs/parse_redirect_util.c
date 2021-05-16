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
