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
