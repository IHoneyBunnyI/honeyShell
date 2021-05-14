#include "minishell.h"

int	find_equal(char *line)
{
	int	i;

	i = -1;
	while (line[++i])
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
	if (s1[i] == '=' || !s1[i])
		return (1);
	return (0);
}

char *ft_only_arg(char *s)
{
	char *copy;
	int i;

	i = 0;
	copy = ft_strdup(s);
	while (copy[i] && copy[i] != '=')
		i++;
	if (copy[i] == '=')
		copy[i] = 0;
	return (copy);
}

int	find_arg_in_env(char *arg, char **args)
{
	int i;
	char *only_arg;

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
	int ret;

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

int	find_index_env(char *arg, char **env)
{
	int i;
	char *only_arg;

	only_arg = ft_only_arg(arg);
	i = 0;
	while (env[i])
	{
		if (ft_strstr(env[i], only_arg))
		{
			free(only_arg);
			return (i);
		}
		i++;
	}
	free(only_arg);
	return (0);
}

void	copy_args(char **new_env, char **args, char **old_env)
{
	int i;
	int j;
	int index;
	char *s;

	j = 0;
	i = -1;
	while(old_env[++i])
		new_env[j++] = old_env[i];
	i = -1;
	while (args[++i])
	{
		s = args[i];
		if (!valid_arg(s))
		{
			error_export(s);
			continue ;
		}
		if (find_arg_in_env(s, old_env))
		{
			if (find_equal(s))
			{
				index = find_index_env(s, new_env);
				char *tmp = new_env[index];
				new_env[index] = ft_strdup(s);
				free(tmp);
			}
			else
				;
		}
		else
			new_env[j++] = ft_strdup(args[i]);
	}

}

void	add_sort_env(t_all *all, char **args)
{
	int		old;
	int		new;
	char	**new_env;

	old = num_of_split(all->env);
	new = check_args(all, args);
	new_env = malloc(sizeof(char *) * (old + new + 1));
	new_env[old + new] = 0;
	copy_args(new_env, args, all->env);
	free(all->env);
	all->env = new_env;
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
