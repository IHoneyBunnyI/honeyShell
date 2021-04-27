#include "minishell.h"

void	skip_args_before_dots(t_all *all, char **args)
{
	int i;

	i = 0;
	while (args[i] && args[i][0] != ';')
		i++;
	/*printf("%s\n", args[i + 1]);*/
	all->all_args = &args[i + 1];
}

int	find_dots(char **args)
{
	int	res;
	int	i;

	i = -1;
	res = 1;
	while (args[++i])
	{
		if (args[i][0] == ';' && args[i + 1] != 0)
			res++;
	}
	return (res);
}

int	check_dots(char **args)
{
	int	i;

	i = 0;
	if (args[0][0] == ';')
	{
		ft_putendl_fd("🚀: syntax error near unexpected token `;'", 2);
		return (0);
	}
	while (args[i])
	{
		if (args[i][0] == ';' && args[i + 1] == 0)
			return (1);
		if (args[i][0] == ';' && args[i + 1][0] == ';')
		{
			ft_putendl_fd("🚀: syntax error near unexpected token `;;'", 2);
			return (0);
		}
		i++;
	}
	return (1);
}

int	parse_cmd(t_all *all, t_cmd *cmd, char **args)
{
	if (check_dots(args) == 0)
		return (0);
	if (!(parse_redirect(all, args, cmd)))
		return (0);
	skip_args_before_dots(all, all->all_args);
	/*int i = 0;*/
	/*while (args[i])*/
	/*{*/
		/*printf("%d, %s\n", all->dots, args[i]);*/
		/*i++;*/
	/*}*/
	return (1);
}

int	is_builtin(t_cmd *cmd)
{
	if (ft_strcmp(cmd->cmd, "echo") == 0 ||
		ft_strcmp(cmd->cmd, "cd") == 0 ||
		ft_strcmp(cmd->cmd, "export") == 0 ||
		ft_strcmp(cmd->cmd, "unset") == 0 ||
		ft_strcmp(cmd->cmd, "exit") == 0 ||
		ft_strcmp(cmd->cmd, "pwd") == 0 ||
		ft_strcmp(cmd->cmd, "env") == 0)
		return (1);
	else
		return (0);
}

void	find_cmd(t_all *all, t_cmd *cmd)
{
	if (ft_strcmp(cmd->cmd, "echo") == 0)
		my_echo(cmd->args + 1, cmd->fd_out);
	else if (ft_strcmp(cmd->cmd, "cd") == 0)
		cd(all, cmd->args);
	else if (ft_strcmp(cmd->cmd, "export") == 0)
		export(all, cmd->args, cmd->fd_out);
	else if (ft_strcmp(cmd->cmd, "unset") == 0)
		my_unset(all, cmd->args + 1);
	else if (ft_strcmp(cmd->cmd, "pwd") == 0)
		pwd(cmd->fd_out);
	else if (ft_strcmp(cmd->cmd, "env") == 0)
		env(all->env, cmd->fd_out);
	else if (ft_strcmp(cmd->cmd, "exit") == 0)
		ft_exit(all, cmd->args + 1);
}

void	free_cmd(t_cmd *cmd)
{
	int	i;

	i = 0;
	while (cmd->args[i])
	{
		free(cmd->args[i]);
		cmd->args[i] = 0;
		i++;
	}
	free(cmd->cmd);
	cmd->cmd = 0;
}

void	work_command(t_all *all, t_tokens *tkn, struct termios *old)
{
	int	fd;
	t_cmd cmd;

	fd = 1;
	ft_putstr(tgetstr("ke", 0));
	tcsetattr(0, TCSANOW, old);
	init_cmd(&cmd);
	all->all_args = convert_tkn(tkn);
	all->dots = find_dots(all->all_args);
	while (all->dots--)
	{
		if (!(parse_cmd(all, &cmd, all->all_args)))
			return ;
		get_args(all->args, &cmd);
		if (is_builtin(&cmd))
			find_cmd(all, &cmd);
		else
		{
			my_execve(all, cmd.args, &cmd);
		}
		free_cmd(&cmd);
	}
}
