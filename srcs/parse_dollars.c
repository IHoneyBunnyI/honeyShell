#include "minishell.h"

char	*find_in_env(char *comand, char **env)
{
	(void)comand;
	(void)env;
	return (0);
}

char	**parse_dollars(char **args, char **env)
{
	char	**ret;
	int		i;

	i = 0;
	while (args[i])
		i++;
	ret = malloc(sizeof(char *) * (i + 1));
	ret[i] = 0;
	i = 0;
	while (args[i])
	{
		if (args[i][0] == '$')
		{
			if (args[i][1] == 0)
				ret[i] = ft_strdup("$");
			else
				ret[i] = check_env(&args[i][1], env);
		}
		else
		{
			ret[i] = ft_strdup(args[i]);
		}
		i++;
	}
	free_split(args);
	return (ret);
}
