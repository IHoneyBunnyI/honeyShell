#include "minishell.h"

void	count_dot(t_all *all, char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] == ';')
			all->dots++;
		i++;
	}
}

