#include "minishell.h"

int	find_len_command(char *line)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	while (line[i] != ' ' && line[i] != '\0')
	{
		if (line[i] != '\'' && line[i] != '"')
			len++;
		i++;
	}
	return (len);
}

void	get_line_command(t_all *all, char *line, int len)
{
	int	i;

	i = 0;
	all->command = malloc(sizeof(char) * (len + 1));
	while (line[i])
	{
		if (line[i] == '"')
			i++;
		else
		{
			all->command[i] = line[i];
			i++;
		}
	}
	all->command[i] = 0;
}

void	get_command(t_all *all, char *line)
{
	int	len;

	len = find_len_command(line);
	get_line_command(all, line, len);
}

void	parser(t_all *all, char *line)
{
	get_command(all, line);
}
