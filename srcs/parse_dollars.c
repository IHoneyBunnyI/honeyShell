#include "minishell.h"

void	next_char(char **str, int *j, char n)
{
	char	*buf;

	buf = malloc(2);
	buf[0] = n;
	buf[1] = '\0';
	*str = ft_strjoin(*str, buf);
	(*j)++;
	free(buf);
}

void	skip_quot(char **ret, int *j, char *args)
{
	(*j)++;
	while (args[*j] != '\'')
		next_char(ret, j, args[*j]);
	(*j)++;
}


void	skip_else(char **ret, int *j, char *args, t_all *all)
{
	char	*buf;

	if (args[*j] == '\"')
		(*j)++;
	if (args[*j] == '$' && args[*j])
	{
		(*j)++;
		if (args[*j] == 0)
			*ret = ft_strjoin(*ret, "$");
		else if (args[*j] == '?')
		{
			*ret = ft_strjoin(*ret, ft_itoa(all->exit_status));
			(*j)++;
		}
		else
		{
			buf = check_env(&args[*j], all->env);
			if (buf)
			{
				*ret = ft_strjoin(*ret, buf);
				free(buf);

			}
			while (skip_env(args[*j]))
				(*j)++;
		}
	}
	else if (args[*j] == '\\' && args[*j])
		next_char(ret, j, args[++*j]);
	else if (args[*j] && args[*j] != '\"' && args[*j] != '\'')
		next_char(ret, j, args[*j]);
}

char	**parse_dollars(t_all *all, char **args)
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
	while (args[i])
	{
		j = 0;
		ret[i] = malloc(1);
		ret[i][0] = '\0';
		while (args[i][j])
		{
			if (args[i][j] == '\'')
				skip_quot(&ret[i], &j, args[i]);
			else
				skip_else(&ret[i], &j, args[i], all);
		}
		i++;
	}
	free_split(args);
	return (ret);
}
