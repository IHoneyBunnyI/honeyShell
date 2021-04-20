/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_work.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchaya <mchaya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 12:48:00 by mchaya            #+#    #+#             */
/*   Updated: 2021/04/20 14:36:44 by mchaya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	tkn_size(t_tokens *lst)
{
	int	count;

	count = 0;
	while (lst && !lst->is_oprt)
	{
		count++;
		lst = lst->next;
	}
	return (count);
}

char	**convert_tkn(t_tokens *tkn)
{
	int		n;
	char	**conv;
	int		i;

	i = 0;
	n = tkn_size(tkn);
	conv = malloc(sizeof(char *) * (n + 1));
	while (tkn && !tkn->is_oprt)
	{
		conv[i] = ft_strdup(tkn->token);
		i++;
		tkn = tkn->next;
	}
	conv[i] = NULL;
	return (conv);
}
