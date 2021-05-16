#include "minishell.h"

char	**sort_env(char **env)
{
	int		i;
	int		j;
	char	*tmp;

	i = 0;
	while (env[i])
	{
		j = 0;
		while (j < i)
		{
			if (ft_strcmp(env[i], env[j]) < 0)
			{
				tmp = env[i];
				env[i] = env[j];
				env[j] = tmp;
			}
			j++;
		}
		i++;
	}
	return (env);
}

char	**copy_env(char **env)
{
	int		i;
	char	**for_sort;

	i = 0;
	while (env[i])
		i++;
	for_sort = malloc(sizeof(char *) * (i + 1));
	if (!for_sort)
		exit(0);
	for_sort[i] = 0;
	while (i--)
	{
		for_sort[i] = ft_strdup(env[i]);
	}
	return (for_sort);
}

void	putstr_before_equal(char *s, int fd)
{
	int	i;

	i = 0;
	while (s[i] && s[i] != '=')
	{
		ft_putchar_fd(s[i], fd);
		i++;
	}
	if (s[i] == '=')
		ft_putchar_fd(s[i], fd);
}

void	putstr_after_equal(char *s, int fd)
{
	int	i;

	i = 0;
	while (s[i] && s[i] != '=')
		i++;
	if (s[i] == '=')
		i++;
	ft_putstr_fd(&s[i], fd);
}

void	print_export(char **env, int fd)
{
	int		i;
	char	**print_env;

	i = 0;
	print_env = copy_env(env);
	print_env = sort_env(print_env);
	while (print_env[i])
	{
		ft_putstr_fd("declare -x ", fd);
		putstr_before_equal(print_env[i], fd);
		if (find_equal(print_env[i]))
			ft_putstr_fd("\"", fd);
		putstr_after_equal(print_env[i], fd);
		if (find_equal(print_env[i]))
			ft_putstr_fd("\"", fd);
		ft_putstr_fd("\n", fd);
		i++;
	}
	free_split(print_env);
}
