/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_history.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchaya <mchaya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 16:30:18 by mchaya            #+#    #+#             */
/*   Updated: 2021/04/17 15:49:01 by mchaya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	exp_env(char **cmnd, int *is_set, char **env, char **tk)
{
	char	*res;

	(*cmnd)++;
	if (ft_isdigit(**cmnd))
		(*cmnd)++;
	else if (!ft_isalpha(**cmnd) || **cmnd == '_')
	{
		*tk = ft_strjoin(*tk, "$");
		*is_set = 1;
	}
	else
	{
		res = check_env(*cmnd, env);
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

int	check_all(char **cmnd, char **env, char *tk, int *is_set)
{
	if (**cmnd == '\'')
	{
		if (!check_sing_quot(cmnd, is_set, &tk))
			return (0);
	}
	else if (**cmnd == '\\')
	{
		if (!check_bs(cmnd, &tk, is_set))
			return (0);
	}
	else if (**cmnd == '$')
		exp_env(cmnd, is_set, env, &tk);
	else if (**cmnd == '\"')
	{
		if (!check_dbl_quot(cmnd, &tk, is_set, env))
			return (0);
	}
	else
		check_symb(cmnd, &tk, is_set);
	return (1);
}

int	check_else(char **cmnd, t_tokens *tmp, char **env, int *is_set)
{
	char	*tk;

	tk = malloc(1);
	tk[0] = '\0';
	while (not_operator(**cmnd) && **cmnd != ' ' && **cmnd != '\0')
	{
		if (!check_all(cmnd, env, tk, is_set))
			return (0);
	}
	tmp->token = tk;
	tmp->next = NULL;
	tmp->is_oprt = 0;
	return (1);
}

t_tokens	*flexer(char *cmnd, char **env)
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
			break ;
		if (!not_operator(*cmnd))
			check_operator(tmp, &cmnd, &is_set);
		else
		{
			if (!check_else(&cmnd, tmp, env, &is_set))
				return (0);
		}
		if (is_set)
			add_elem(&tkn, tmp);
	}
	return (tkn);
}
