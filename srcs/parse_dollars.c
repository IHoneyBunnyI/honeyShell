#include "minishell.h"

char	*find_in_env(char *comand, char **env)
{
	(void)comand;
	(void)env;
	return 0;
}

char	**parse_dollars(char **args, char **env)
{
	(void)env;
	char **ret;
	int i;

	i = 0;
	while (args[i])
		i++;
	ret = malloc(sizeof(char *) * (i + 1));
	ret[i] = 0;
	i = 0;
	/*for (int i = 0; args[i]; i++)*/
		/*printf("%s\n", args[i]);*/
	while (args[i])
	{
		if (args[i][0] == '$')
		{
			/*printf("%s\n", args[i]);*/
			ret[i] = check_env(&args[i][1], env);
			/*printf("%s\n", ret[i]);*/
		}
		else
		{
			ret[i] = ft_strdup(args[i]);
		}
		i++;
	}
	/*for (int i = 0; ret[i]; i++)*/
		/*printf("%s\n", ret[i]);*/
	free_split(args);
	return (ret);
}

