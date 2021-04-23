#include "libft.h"

char	*ft_strdup(const char *src)
{
	int		j;
	int		len;
	char	*str;

	len = 0;
	j = 0;
	while (src[len])
		len++;
	str = (char *)malloc(sizeof(*str) * (len + 1));
	if (!str)
		return (NULL);
	while (j < len)
	{
		str[j] = src[j];
		j++;
	}
	str[j] = '\0';
	return (str);
}
