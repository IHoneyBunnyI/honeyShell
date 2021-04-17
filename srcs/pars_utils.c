/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchaya <mchaya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 13:51:30 by mchaya            #+#    #+#             */
/*   Updated: 2021/04/16 16:53:20 by mchaya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_angelina(char *p1, char *p2)
{
	char	*res;
	int		i;

	i = 0;
	res = malloc(p2 - p1 - 1);
	p1++;
	while (p1 != p2)
	{
		res[i] = *p1;
		i++;
		p1++;
	}
	res[i] = '\0';
	return (res);
}

void	add_elem(t_tokens **tkn, t_tokens *tmp)
{
	t_tokens	*plst;

	if (!tkn)
		return ;
	plst = *tkn;
	if (!*tkn)
	{
		*tkn = tmp;
		return ;
	}
	if (!tmp)
		return ;
	while (plst->next)
		plst = plst->next;
	plst->next = tmp;
}

int	not_operator(char cmnd)
{
	if (cmnd == ';' || cmnd == '|' || cmnd == '<' || cmnd == '>')
		return (0);
	return (1);
}

char	*make_cpy(char *src)
{
	char	*res;
	int		len;
	int		i;

	i = 0;
	len = ft_strlen(src);
	res = malloc(len + 1);
	if (!res)
		return (0);
	while (src[i])
	{
		res[i] = src[i];
		i++;
	}
	res[i] = '\0';
	return (res);
}

int	skip_env(char s)
{
	if (ft_isalnum(s) || s == '_')
		return (1);
	return (0);
}
