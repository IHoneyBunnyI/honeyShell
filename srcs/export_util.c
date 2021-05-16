#include "minishell.h"

int	find_equal(char *line)
{
	int	i;

	i = -1;
	while (line[++i])
	{
		if (line[i] == '=')
			return (1);
	}
	return (0);
}

int	num_of_split(char **split)
{
	int	i;

	i = 0;
	while (split[i])
		i++;
	return (i);
}

int	arg_lenth(char *s)
{
	int	i;

	i = 0;
	while (s[i] && s[i] != '=')
		i++;
	return (i);
}

int	ft_strstr(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s2[i])
	{
		if (s1[i] == s2[i])
			i++;
		else
			return (0);
	}
	if (s1[i] == '=' || !s1[i])
		return (1);
	return (0);
}

char	*ft_only_arg(char *s)
{
	char	*copy;
	int		i;

	i = 0;
	copy = ft_strdup(s);
	while (copy[i] && copy[i] != '=')
		i++;
	if (copy[i] == '=')
		copy[i] = 0;
	return (copy);
}
