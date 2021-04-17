/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchaya <mchaya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 19:48:41 by mchaya            #+#    #+#             */
/*   Updated: 2021/04/17 15:14:27 by mchaya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	exit_error(char *str)
{
	printf("%s\n", str);
	return (0);
}

char	*exit_env(char *cmnd_cpy, char *env_cpy, int k)
{
	char	*res;

	free(cmnd_cpy);
	res = make_cpy(env_cpy + (++k));
	free(env_cpy);
	return (res);
}

void	operator_utils(t_tokens *tmp, char **cmnd, int *is_set)
{
	tmp->is_oprt = 1;
	tmp->token = malloc(2);
	tmp->token[0] = **cmnd;
	tmp->token[1] = '\0';
	tmp->next = NULL;
	(*cmnd)++;
	*is_set = 1;
}

void	dbl_quot_bs(char **cmnd, char **tk)
{
	char	t[3];

	(*cmnd)++;
	if (**cmnd == '$' || **cmnd == '`' || **cmnd == '\\'
		|| **cmnd == '\"')
	{
		t[0] = **cmnd;
		t[1] = '\0';
	}
	else
	{
		t[0] = '\\';
		t[1] = **cmnd;
		t[2] = '\0';
	}
	*tk = ft_strjoin(*tk, t);
	(*cmnd)++;
}
