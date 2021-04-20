/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvernon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 16:35:41 by rvernon           #+#    #+#             */
/*   Updated: 2021/04/20 12:14:18 by mchaya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*plist;
	t_list	*ptmp;

	if (!*lst)
		return ;
	plist = *lst;
	ptmp = *lst;
	while (plist)
	{
		if (del != NULL)
			del(plist->content);
		ptmp = plist->next;
		free(plist);
		plist = ptmp;
	}
	*lst = NULL;
}
