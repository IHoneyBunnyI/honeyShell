#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*a;

	a = (unsigned char *)s;
	while (n > 0)
	{
		*a = '\0';
		a++;
		n--;
	}
}
