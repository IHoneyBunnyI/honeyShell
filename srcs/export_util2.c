#include "minishell.h"

int	find_arg_in_env(char *arg, char **args)
{
	int		i;
	char	*only_arg;

	only_arg = ft_only_arg(arg);
	i = 0;
	while (args[i])
	{
		if (ft_strstr(args[i], only_arg))
		{
			free(only_arg);
			return (1);
		}
		i++;
	}
	free(only_arg);
	return (0);
}

int	valid_arg(char *s)
{
	int	i;

	i = 0;
	if (ft_isdigit(s[0]) || s[0] == '=' || s[0] == '+')
		return (0);
	while (s[i] && s[i] != '=')
	{
		if (!ft_isalnum(s[i]) && s[i] != '_' && \
			!(s[i] == '+' && s[i + 1] == '='))
			return (0);
		i++;
	}
	return (1);
}

void	error_export(char *s)
{
	ft_putstr_fd("🚀: export: ", 2);
	ft_putstr_fd(s, 2);
	ft_putendl_fd(": not a valid identifier", 2);
}

int	check_args(t_all *all, char **args)
{
	int		i;
	char	*s;
	int		ret;

	i = -1;
	ret = 0;
	while (args[++i])
	{
		s = args[i];
		if (!valid_arg(s))
		{
			error_export(s);
			continue ;
		}
		if (find_arg_in_env(s, all->env))
			;
		else
			ret++;
	}
	return (ret);
}
