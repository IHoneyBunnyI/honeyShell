#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	unsigned char	*pc;

	pc = (unsigned char *)s;
	while (*pc != '\0' && *pc != (unsigned char)c)
	{
		pc++;
	}
	if (*pc == (unsigned char)c)
	{
		return ((char *)pc);
	}
	else
		return (NULL);
}
