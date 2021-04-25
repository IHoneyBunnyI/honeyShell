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

void	parse_cmd(t_all *all, t_cmd *cmd, char **args)
{
	parse_redirect(all, args, cmd);
}

void	work_command(t_all *all, t_tokens *tkn)
{
	int	fd;
	t_cmd cmd;

	fd = 1;
	init_cmd(&cmd);
	all->all_args = convert_tkn(tkn);
	all->dots = find_dots(all->all_args);
	while (all->dots--)
	{
		parse_cmd(all, &cmd, all->all_args);
		get_args(all->args, &cmd);
	}
}
