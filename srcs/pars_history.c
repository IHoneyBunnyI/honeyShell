#include "minishell.h"

void	exp_env(char **cmnd, int *is_set, char **tk, t_all *all)
{
	char	*res;

	(*cmnd)++;
	if (ft_isdigit(**cmnd))
		(*cmnd)++;
	else if (**cmnd == '?')
	{
		(*cmnd)++;
		*tk = ft_strjoin(*tk, ft_itoa(all->exit_status));
		*is_set = 1;
	}
	else if (!ft_isalpha(**cmnd) || **cmnd == '_')
	{
		*tk = ft_strjoin(*tk, "$");
		*is_set = 1;
	}
	else
	{
		res = check_env(*cmnd, all->env);
		*tk = ft_strjoin(*tk, res);
		while (skip_env(**cmnd))
			(*cmnd)++;
		if (ft_strcmp(res, ""))
			*is_set = 1;
	}
}

void	check_symb(char **cmnd, char **tk, int *is_set)
{
	char	t[2];

	t[1] = 0;
	t[0] = **cmnd;
	*tk = ft_strjoin(*tk, t);
	if (**cmnd)
		(*cmnd)++;
	*is_set = 1;
}

int	check_all(char **cmnd, char **tk, int *is_set, t_all *all)
{
	if (**cmnd == '\'')
	{
		if (!check_sing_quot(cmnd, is_set, tk))
			return (0);
	}
	else if (**cmnd == '\\')
	{
		if (!check_bs(cmnd, tk, is_set))
			return (0);
	}
	else if (**cmnd == '$')
		exp_env(cmnd, is_set, tk, all);
	else if (**cmnd == '\"')
	{
		if (!check_dbl_quot(cmnd, tk, is_set, all))
			return (0);
	}
	else
		check_symb(cmnd, tk, is_set);
	return (1);
}

int	check_else(char **cmnd, t_tokens *tmp, int *is_set, t_all *all)
{
	char	*tk;

	tk = malloc(1);
	tk[0] = '\0';
	while (not_operator(**cmnd) && **cmnd != ' ' && **cmnd != '\0')
	{
		if (!check_all(cmnd, &tk, is_set, all))
		{
			free(tk);
			return (0);
		}
	}
	tmp->token = tk;
	tmp->next = NULL;
	tmp->is_oprt = 0;
	return (1);
}

t_tokens	*flexer(char *cmnd, t_all *all)
{
	t_tokens	*tkn;
	t_tokens	*tmp;
	int			is_set;

	tkn = NULL;
	while (*cmnd)
	{
		is_set = 0;
		tmp = malloc(sizeof(t_tokens));
		while (*cmnd == ' ' && *cmnd)
			cmnd++;
		if (*cmnd == '\0')
		{
//			free(tmp->token);
//			free(tmp);
			break;
		}
		if (!not_operator(*cmnd))
			check_operator(tmp, &cmnd, &is_set);
		else
		{
			if (!check_else(&cmnd, tmp, &is_set, all))
			{
//				free(tmp->token);
//				free(tmp);
				return (0);
			}
		}
		if (is_set)
			add_elem(&tkn, tmp);
//		free(tmp->token);
//		free(tmp);
	}
	return (tkn);
}
