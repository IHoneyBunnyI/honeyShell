#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned int	j;

	j = 0;
	while (j < n && s1[j] != '\0' && s2[j] != '\0')
	{
		if (s1[j] != s2[j])
		{
			return ((unsigned char)s1[j] - (unsigned char)s2[j]);
		}
		j++;
	}
	if (j < n && (s1[j] || s2[j]))
		return ((unsigned char)s1[j] - (unsigned char)s2[j]);
	return (0);
}
