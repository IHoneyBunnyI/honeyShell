#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t			i;
	unsigned char	*strsrc;
	unsigned char	*strdst;

	i = 0;
	strsrc = (unsigned char *)src;
	strdst = (unsigned char *)dst;
	if (strsrc < strdst)
	{
		while (len--)
			strdst[len] = strsrc[len];
	}
	if (strsrc > strdst)
	{
		while (i++ < len)
		{
			*strdst = *strsrc;
			strsrc++;
			strdst++;
		}
	}
	return (dst);
}
