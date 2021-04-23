#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char			*pc;
	unsigned int	i;

	i = 0;
	pc = (char *)s;
	while (s[i] != '\0')
		i++;
	i++;
	while (i--)
	{
		if (s[i] == (char)c)
			return (pc + i);
	}
	return (NULL);
}
