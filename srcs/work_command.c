#include "minishell.h"

int	find_dots(char **args)
{
	int	res;
	int	i;

	i = -1;
	res = 1;
	while (args[++i])
	{
		if (args[i][0] == ';')
			res++;
	}
	return (res);
}

char	**parse_cmd(t_cmd *cmd, char **args)
{
	int	i;

	i = 0;
	parse_redirect(args, cmd);
	while (args[i] && args[i][0] != ';')
	{
		i++;
	}
	return (&args[i]);
}

void	work_command(t_all *all, t_tokens *tkn)
{
	int	fd;
	t_cmd cmd;

	fd = 1;
	init_cmd(&cmd);
	all->all_args = convert_tkn(tkn);
	/*for (int i = 0; all->all_args[i] != 0; i++)*/
		/*printf("%s\n", all->all_args[i]);*/
	all->dots = find_dots(all->all_args);
	while (all->dots--)
	{
		all->all_args = parse_cmd(&cmd, all->all_args) + 1;
	}
}
