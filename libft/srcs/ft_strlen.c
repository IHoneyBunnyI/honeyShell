#include "libft.h"

int	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (*s++ != '\0')
		i++;
	return (i);
}
