#include "minishell.h"

int	find_equal(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] == '=')
			return (1);
	}
	return (0);
}

int	num_of_split(char **split)
{
	int	i;

	i = 0;
	while (split[i])
		i++;
	return (i);
}

int	arg_lenth(char *s)
{
	int i;

	i = 0;
	while (s[i] && s[i] != '=')
		i++;
	return (i);
}

int	ft_strstr(char *s1, char *s2)
{
	int i;

	i = 0;
	while (s2[i])
	{
		if (s1[i] == s2[i])
			i++;
		else
			return (0);
	}
	if (s1[i] == '=')
		return (1);
	return (0);
}

int	find_arg_in_env(char *arg, char **args)
{
	int i;
	int	arg_len;

	(void)arg;
	i = 0;
	arg_len = 0;
	while (args[i])
	{
		arg_len = arg_lenth(args[i]);
		if (ft_strstr(args[i], arg))
			return (1);
		i++;
	}
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
		if (!ft_isalnum(s[i]) && s[i] != '_' && !(s[i] == '+' && s[i + 1] == '='))
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
	int i;
	char *s;

	i = -1;
	while (args[++i])
	{
		s = args[i];
		if (!valid_arg(s))
		{
			error_export(s);
			continue ;
		}
		if (find_arg_in_env(s, all->env))
			printf("NASHEL\n");
	}
	return (0);
}

void	add_sort_env(t_all *all, char **args)
{
	int		old;
	int		new;
	/*char	**new_env;*/

	old = num_of_split(all->env);
	new = check_args(all, args);
	/*free(all->env);*/
	/*all->env = new_env;*/
}

void	export(t_all *all, char **args, int fd)
{
	int	i;

	i = 0;
	while (args[i])
		i++;
	if (i == 1)
		print_export(all->env, fd);
	else
		add_sort_env(all, args + 1);
}
