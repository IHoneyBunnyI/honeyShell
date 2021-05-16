#include "minishell.h"

int	find_dots(char **args)
{
	int	res;
	int	i;

	i = -1;
	res = 1;
	while (args[++i])
	{
		if (args[i][0] == '|')
			res++;
		else if (args[i][0] == ';' && args[i + 1] != 0)
			res++;
	}
	return (res);
}

int	exit_zero(char *str)
{
	ft_putendl_fd(str, 2);
	return (0);
}

int	check_dots(char **args)
{
	int	i;
	int	dots;

	i = 0;
	dots = 0;
	dots = count_dots(args);
	if (dots == 1)
	{
		if (ft_strcmp(args[0], ";") == 0)
			return (exit_zero("🚀: syntax error near unexpected token `;'"));
	}
	if (dots > 1 && args[0][0] == ';' && args[1][0] != ';')
		return (exit_zero("🚀: syntax error near unexpected token `;'"));
	while (args[i])
	{
		if (args[i][0] == ';' && args[i + 1] == 0)
			return (1);
		if (args[i][0] == ';' && args[i + 1][0] == ';')
			return (exit_zero("🚀: syntax error near unexpected token `;;'"));
		i++;
	}
	return (1);
}

int	error_pipe(void)
{
	ft_putendl_fd("🚀: syntax error near unexpected token `|'", 2);
	return (0);
}

int	check_pipes(char **args)
{
	int	i;
	int	pipes;

	i = 0;
	pipes = 0;
	pipes = count_pipes(args);
	if (pipes == 1)
		if (ft_strcmp(args[0], "|") == 0)
			return (error_pipe());
	if (pipes > 1 && args[0][0] == '|' && args[1][0] != '|')
		return (error_pipe());
	while (args[i])
	{
		if (args[i][0] == '|' && args[i + 1] == 0)
			return (error_pipe());
		if (args[i][0] == '|' && args[i + 1][0] == '|')
		{
			ft_putendl_fd("🚀: syntax error near unexpected token `|'", 2);
			return (0);
		}
		i++;
	}
	return (1);
}
