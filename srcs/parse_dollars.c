#include "minishell.h"

char	*find_in_env(char *comand, char **env)
{
	(void)comand;
	(void)env;
	return (0);
}

/*void	next_char(char *str, int *j, char n)
{
	char	*buf;

	buf = malloc(2);
	buf[0] = n;
	buf[1] = '\0';
	str = ft_strjoin(str, buf);
	(*j)++;
	free(buf);
}*/

char	**parse_dollars(t_all *all, char **args, char **env)
{
	char	**ret;
	int		i;
	int		j;
	char	*buf;

	i = 0;
	while (args[i])
		i++;
	ret = malloc(sizeof(char *) * (i + 1));
	ret[i] = 0;
	i = 0;
	j = 0;
	buf = malloc(2);
	buf[1] = '\0';
	while (args[i])
	{
		ret[i] = malloc(1);
		ret[i][0] = '\0';
		while (args[i][j])
		{
			if (args[i][j] == '\'')
			{
				j++;
				while (args[i][j] != '\'')
				{
					buf[0] = args[i][j];
					ret[i] = ft_strjoin(ret[i], buf);
					j++;
				}

				j++;
			}
			else
			{
				if (args[i][j] == '\"')
					j++;
				if (args[i][j] == '$' && args[i][j])
				{
					j++;
					if (args[i][j] == 0)
						ret[i] = ft_strjoin(ret[i], "$");
					else if (args[i][j] == '?')
					{
						ret[i] = ft_strjoin(ret[i], ft_itoa(all->exit_status));
						j++;
					}
					else
					{
						ret[i] = ft_strjoin(ret[i], check_env(&args[i][j],
									env));
						while (skip_env(args[i][j]))
							j++;
					}
				}
				else if (args[i][j] == '\\' && args[i][j])
				{
					j++;
					buf[0] = args[i][j];
					ret[i] = ft_strjoin(ret[i], buf);
					j++;
				}
				else if (args[i][j] && args[i][j] != '\"' && args[i][j] != '\'')
				{
					buf[0] = args[i][j];
					ret[i] = ft_strjoin(ret[i], buf);
					j++;
				}
			}
		}
		i++;
		j = 0;
	}
	free(buf);
	free_split(args);
	return (ret);
}
