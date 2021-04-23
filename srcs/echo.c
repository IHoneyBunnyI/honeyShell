#include "minishell.h"

int	is_n(char *line)
{
	int	i;

	i = 0;
	if (line[i] == '-' && line[i + 1] == 'n')
	{
		i = 0;
		while (line[++i])
		{
			if (line[i] != 'n')
				return (0);
		}
		return (1);
	}
	return (0);
}

void	my_echo(char **s)
{
	int		i;
	char	n;

	n = '\n';
	i = 0;
	while (s[i] && is_n(s[i]))
	{
		i++;
	}
	if (i > 0)
		n = '\0';
	while (s[i])
	{
		write(1, s[i], ft_strlen(s[i]));
		i++;
		if (s[i])
			write(1, " ", 1);
	}
	write(1, &n, 1);
}
