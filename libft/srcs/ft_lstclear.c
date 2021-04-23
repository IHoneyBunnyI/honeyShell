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
