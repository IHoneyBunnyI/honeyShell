#include "minishell.h"

void	write_start_line(char *line)
{
	int	len;

	len = ft_strlen(line);
	write(2, line, len);
}

void	init_const(t_all *all)
{
	all->start_line = ft_strdup("🚀 $ ");
}

int	is_echo(char *l)
{
	if (l[0] == 'e' && l[1] == 'c' && l[2] == 'h' && l[3] == 'o')
		return (1);
	return (0);
}

int	count_dots(char **args)
{
	int	dots;
	int	i;

	dots = 0;
	i = 0;
	while (args[i])
	{
		if (ft_strcmp(args[i], ";") == 0)
			dots++;
		i++;
	}
	return (dots);
}

void	free_split(char **split)
{
	int	i;

	i = 0;
	while (split[i])
		free(split[i++]);
	free(split);
}
