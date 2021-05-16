#include "minishell.h"

int	is_empty(char *s)
{
	int	i;

	i = 0;
	while (s[i] && s[i] != '=')
		i++;
	if (!s[i])
		return (1);
	if (s[i + 1] != '\0')
		return (0);
	else
		return (1);
}

int	env(char **s, int fd)
{
	int	i;

	i = -1;
	while (s[++i])
	{
		if (!is_empty(s[i]))
			ft_putendl_fd(s[i], fd);
	}
	return (0);
}
