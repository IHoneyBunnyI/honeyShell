#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*str;

	str = (unsigned char *)dst;
	if (!dst && !src)
	{
		return (dst);
	}
	while (n > 0)
	{
		*str = *((unsigned char *)src);
		str++;
		src++;
		n--;
	}
	return (dst);
}
