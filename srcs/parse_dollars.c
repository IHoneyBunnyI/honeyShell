#include "minishell.h"

char	*find_in_env(char *comand, char **env)
{
	(void)comand;
	(void)env;
	return (0);
}

char	**parse_dollars(t_all *all, char **args, char **env)
{
	char	**ret;
	int		i;
	int		j;

	i = 0;
	while (args[i])
		i++;
	ret = malloc(sizeof(char *) * (i + 1));
	ret[i] = 0;
	i = 0;
	j = 0;
	while (args[i])
	{
		while (args[i][j])
		{
			if (args[i][j] == '$')
			{
				if (args[i][j + 1] == 0)
					ret[i] = ft_strdup("$");
				else if (args[i][j + 1] == '?')
					ret[i] = ft_strdup(ft_itoa(all->exit_status));
				else
					ret[i] = check_env(&args[i][j + 1], env);
			}
			else
			{
				ret[i] = ft_strdup(args[i]);
			}
			j++;
		}
		i++;
	}
	free_split(args);
	return (ret);
}
