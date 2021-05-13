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
	char	*buf;
	//int		is_set;

	i = 0;
	while (args[i])
		i++;
	ret = malloc(sizeof(char *) * (i + 1));
	i = 0;
	j = 0;
	buf = malloc(2);
	buf[1] = '\0';
/*	while (*cmnd)
	{
		is_set = 0;
		if (**cmnd == '\0')
			break;
		if (!not_operator(cmnd))
			check_operator(tmp, &cmnd, &is_set);
		else
		{
			if (!check_else(&cmnd, tmp, &is_set))
				return (0);
		}
		if (is_set)
			add_elem(&tkn, tmp);
	}*/
	while(args[i])
	{
		ret[i] = malloc(1);
		ret[i][0] = '\0';
		while(args[i][j])
		{
			if (args[i][j] == '$')
			{
				j++;
				if (args[i][j] == 0)
					ret[i] = ft_strjoin(ret[i], "$");
				else if (args[i][j] == '?')
					ret[i] = ft_strjoin(ret[i], ft_itoa(all->exit_status));
				else
				{
					ret[i] = ft_strjoin(ret[i], check_env(&args[i][j],
														  env));
					while(skip_env(args[i][j]))
						j++;
				}
			}
			if (args[i][j] == '\\')
				j++;
			buf[0] = args[i][j];
			ret[i] = ft_strjoin(ret[i], buf);
			j++;
		}
		i++;
		j = 0;
	}
	free_split(args);
	return (ret);
}
