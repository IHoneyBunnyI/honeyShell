/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvernon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 16:58:24 by rvernon           #+#    #+#             */
/*   Updated: 2020/11/09 17:30:04 by rvernon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list *newlst;
	t_list *pnew;

	if (!lst)
		return (NULL);
	if (!(newlst = ft_lstnew(f(lst->content))))
		return (NULL);
	lst = lst->next;
	pnew = newlst;
	while (lst)
	{
		if (!(newlst->next = ft_lstnew(f(lst->content))))
		{
			ft_lstclear(&pnew, del);
			return (NULL);
		}
		lst = lst->next;
		newlst = newlst->next;
	}
	return (pnew);
}
