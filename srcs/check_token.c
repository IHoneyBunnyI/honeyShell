#include "minishell.h"

char	*check_env(char *cmnd, char **env)
{
	char	*cmnd_cpy;
	char	*env_cpy;
	int		i;
	int		k;

	i = 0;
	cmnd_cpy = ft_strdup(cmnd);
	while (skip_env(cmnd_cpy[i]))
		i++;
	cmnd_cpy[i] = '\0';
	i = 0;
	while (env[i])
	{
		k = 0;
		env_cpy = ft_strdup(env[i]);
		while (env_cpy[k] != '=')
			k++;
		env_cpy[k] = '\0';
		if (!ft_strcmp(env_cpy, cmnd_cpy))
			return (exit_env(cmnd_cpy, env_cpy, k));
		free(env_cpy);
		i++;
	}
	free(cmnd_cpy);
	return ("");
}

void	check_operator(t_tokens *tmp, char **cmnd, int *is_set)
{
	if (**cmnd == ';' || **cmnd == '|' || **cmnd == '<')
		operator_utils(tmp, cmnd, is_set);
	else if (**cmnd == '>')
	{
		tmp->is_oprt = 1;
		if (*((*cmnd) + 1) == '>')
		{
			tmp->token = malloc(3);
			tmp->token[1] = **cmnd;
			tmp->token[2] = '\0';
			(*cmnd)++;
		}
		else
		{
			tmp->token = malloc(2);
			tmp->token[1] = '\0';
		}
		tmp->token[0] = '>';
		tmp->next = NULL;
		(*cmnd)++;
		*is_set = 1;
	}
}

int	check_sing_quot(char **cmnd, int *is_set, char **tk)
{
	char	*p1;
	char	*p2;
	char	*str;

	p1 = *cmnd;
	p2 = *cmnd;
	p2++;
	while (*p2 && *p2 != '\'')
		p2++;
	if (!(*p2))
		return (exit_zero("parse error: unclosed quotation"));
	str = ft_angelina(p1, p2);
	*tk = ft_strjoin(*tk, str);
	free(str);
	*cmnd = p2 + 1;
	*is_set = 1;
	return (1);
}

int	check_bs(char **cmnd, char **tk, int *is_set)
{
	char	t[2];

	t[1] = 0;
	(*cmnd)++;
	if (!(**cmnd))
		return (exit_zero("parse error: escaped newline"));
	t[0] = **cmnd;
	*tk = ft_strjoin(*tk, t);
	if (*cmnd)
		(*cmnd)++;
	*is_set = 1;
	return (1);
}

int	check_dbl_quot(char **cmnd, char **tk, int *is_set)
{
	char	t[2];

	*is_set = 1;
	(*cmnd)++;
	while (**cmnd != '\"' && **cmnd != '\0')
	{
		if (**cmnd == '\\')
			dbl_quot_bs(cmnd, tk);
		if (**cmnd != '\"')
		{
			t[0] = **cmnd;
			t[1] = '\0';
			*tk = ft_strjoin(*tk, t);
			(*cmnd)++;
		}
	}
	if (!(**cmnd))
		return (exit_zero("parse error: unclosed quotation"));
	(*cmnd)++;
	return (1);
}
