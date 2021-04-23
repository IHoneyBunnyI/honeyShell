#include "libft.h"

static int	wlen(const char *s, char c)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	while (s[i])
	{
		if (s[i] == c)
			return (len);
		if (s[i] == '\0')
			return (len);
		i++;
		len++;
	}
	return (len);
}

static int	wcount(const char *s, char c)
{
	int		count;
	int		i;

	count = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
			count++;
		i++;
	}
	return (count);
}

static char	*get_split(const char *s, int i, char **split, int len)
{
	int		j;
	char	*line;

	line = malloc(sizeof(char) * (len + 1));
	if (!line)
	{
		i = 0;
		while (split[i])
			free(split[i++]);
		free(split);
		return (NULL);
	}
	j = 0;
	while (j < len)
		line[j++] = *s++;
	line[j] = '\0';
	return (line);
}

char	**ft_split(char const *s, char c)
{
	char	**split;
	int		i;
	int		len;
	int		count;

	if (!s)
		return (NULL);
	count = wcount(s, c);
	split = malloc(sizeof(char *) * (count + 1));
	if (!split)
		return (NULL);
	i = -1;
	while (++i < count)
	{
		while (*s == c && *s != '\0')
			s++;
		len = wlen(s, c);
		split[i] = get_split(s, i, split, len);
		if (!split[i])
			return (NULL);
		s += len;
	}
	split[i] = NULL;
	return (split);
}
