/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvernon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 12:01:24 by rvernon           #+#    #+#             */
/*   Updated: 2021/04/15 07:17:16 by rvernon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*plst;

	if (!lst)
		return ;
	plst = *lst;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	if (!new)
		return ;
	while (plst->next)
		plst = plst->next;
	plst->next = new;
}
