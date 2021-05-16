#include "minishell.h"

int	find_index_env(char *arg, char **env)
{
	int		i;
	char	*only_arg;

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

void	replace_env(char **new_env, char *s)
{
	char	*tmp;
	int		index;

	index = find_index_env(s, new_env);
	tmp = new_env[index];
	new_env[index] = ft_strdup(s);
	free(tmp);
}

void	copy_args(char **new_env, char **args, char **old_env)
{
	int		i;
	int		j;
	char	*s;

	j = 0;
	i = -1;
	while (old_env[++i])
		new_env[j++] = old_env[i];
	i = -1;
	while (args[++i])
	{
		s = args[i];
		if (!valid_arg(s))
			continue ;
		if (find_arg_in_env(s, old_env))
		{
			if (find_equal(s))
				replace_env(new_env, s);
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
