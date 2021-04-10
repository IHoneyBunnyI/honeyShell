/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_history.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchaya <mchaya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 16:30:18 by mchaya            #+#    #+#             */
/*   Updated: 2021/04/10 15:46:34 by mchaya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"
#include "libft.h"

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
	t_tokens *plst;

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

t_tokens	*flexer(char *cmnd)
{
	t_tokens	*tkn;
	t_tokens	*tmp;
	char		*tk;
	char		*str;

	tkn = NULL;
	while (*cmnd)
	{
		tmp = malloc(sizeof(t_tokens));
		while (*cmnd == ' ' && *cmnd)
			cmnd++;
		if (*cmnd == '\0')
			break;
		if (*cmnd == ';' || *cmnd == '|' || *cmnd == '<')
		{
			tmp->is_oprt = 1;
			tmp->token = malloc(2);
			tmp->token[0] = *cmnd;
			tmp->token[1] = '\0';
			tmp->next = NULL;
			cmnd++;
		}
		else if (*cmnd == '>')
		{
			tmp->is_oprt = 1;
			if (*(cmnd + 1) == '>')
			{
				tmp->token = malloc(3);
				tmp->token[1] = *cmnd;
				tmp->token[2] = '\0';
				cmnd++;
			}
			else
			{
				tmp->token = malloc(2);
				tmp->token[1] = '\0';
			}
			tmp->token[0] = '>';
			tmp->next = NULL;
			cmnd++;
		}
		else
		{
			tk = malloc(1);
			tk[0] = '\0';   //tk = "";
			while (not_operator(*cmnd) && *cmnd != ' ' && *cmnd != '\0')
			{

				if (*cmnd == '\'')
				{
					char *p1;
					char *p2;

					p1 = cmnd;
					p2 = cmnd;
					p2++;
					while (*p2 && *p2 != '\'')
						p2++;
					str = ft_angelina(p1, p2);
					tk = ft_strjoin(tk, str);
					cmnd = p2 + 1;
				}
				else if (*cmnd == '\\')
				{
					char t[2];
					t[1] = 0;
					cmnd++;
					t[0] = *cmnd;
					tk = ft_strjoin(tk, t);
					if (*cmnd)
						cmnd++;
				}
					/*
					 * TODO Доделать двойные кавычки и переменные
					 */
				else
				{
					char t[2];
					t[1] = 0;
					t[0] = *cmnd;
					tk = ft_strjoin(tk, t);
					if (*cmnd)
						cmnd++;
				}
			}
			tmp->token = tk;
			tmp->next = NULL;
			tmp->is_oprt = 0;
		}
		add_elem(&tkn, tmp);
	}
	return (tkn);
}

int main()
{
	char *str = " 'e''c''h''o'>2; 'h''e''l''l''o'";
	t_tokens	*tkn;

	tkn = flexer(str);
	while (tkn)
	{
		printf("tk = %s, oprt = %d\n", tkn->token, tkn->is_oprt);
		tkn = tkn->next;
	}
	return (0);
}