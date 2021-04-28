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

int check_pipes(char **args)
{
	int	i;

	i = 0;
	if (args[0][0] == '|' && args[1] == 0)
	{
		ft_putendl_fd("🚀: syntax error near unexpected token `|'", 2);
		return (0);
	}
	if (args[0][0] == '|' && args[1][0] == '|')
	{
		ft_putendl_fd("🚀: syntax error near unexpected token `||'", 2);
		return (0);
	}
	while (args[i])
	{
		if (args[i][0] == '|' && args[i + 1][0] == '|')
		{
			ft_putendl_fd("🚀: syntax error near unexpected token `|'", 2);
			return (0);
		}
		i++;
	}
	return (1);
}

int	is_builtin(t_cmd *cmd)
{
	if (cmd->cmd != 0)
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

int	parse_args(t_all *all, t_cmd *cmd, char **args)
{
	(void)cmd;
	(void)args;
	/*if (check_pipes(args) == 0)*/
		/*return (0);*/
	all->args = parse_dollars(all->all_args, all->env);
	if (!all->args)
		return (0);
	if (!(parse_redirect(all, args, cmd)))
		return (0);
	if (!(parse_pipes(all, args, cmd)))
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

void	work_command(t_all *all, t_tokens *tkn, struct termios *old)
{
	t_cmd			cmd;

	kill_new_terminal(old);
	init_cmd(&cmd);
	all->all_args = convert_tkn(tkn);
	if (check_dots(all->all_args) == 0)
		return ;
	all->dots = find_dots(all->all_args);
	while (all->dots--)
	{
		if (!(parse_args(all, &cmd, all->all_args)))
			return ;
		get_args(all->args, &cmd);
		if (is_builtin(&cmd))
			find_cmd(all, &cmd);
		else
		{
			my_execve(all, cmd.args, &cmd);
		}
		/*free_cmd(&cmd);*/
	}
}
