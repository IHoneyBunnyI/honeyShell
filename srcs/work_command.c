#include "minishell.h"

int	is_builtin(t_cmd *cmd)
{
	if (cmd->cmd != 0)
	{
		if (ft_strcmp(cmd->cmd, "echo") == 0 || ft_strcmp(cmd->cmd, "cd") == 0
			|| ft_strcmp(cmd->cmd, "export") == 0
			|| ft_strcmp(cmd->cmd, "unset") == 0
			|| ft_strcmp(cmd->cmd, "exit") == 0
			|| ft_strcmp(cmd->cmd, "pwd") == 0
			|| ft_strcmp(cmd->cmd, "env") == 0)
			return (1);
		else
			return (0);
	}
	return (0);
}

void	find_cmd(t_all *all, t_cmd *cmd)
{
	if (ft_strcmp(cmd->cmd, "echo") == 0)
		my_execve(all, cmd->args, cmd);
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
	if (cmd->fd_out != 1)
	{
		close(cmd->fd_out);
		cmd->fd_out = 1;
	}
	if (cmd->fd_in != 0)
	{
		close(cmd->fd_in);
		cmd->fd_in = 0;
	}
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
	free(cmd->args);
	free(cmd->cmd);
	cmd->cmd = 0;
}

int	parse_args(t_all *all, t_cmd *cmd, char **args)
{
	(void)cmd;
	(void)args;
	all->args = parse_dollars(all, all->args);
	if (!all->args)
		return (0);
	if (!(parse_redirect(all, all->args, cmd)))
		return (0);
	if (!(parse_pipes(all, all->args, cmd)))
		return (0);
	return (1);
}

char	**set_args(char ***pos, t_cmd *cmd)
{
	int		i;
	char	**ret;
	char	**position;

	i = 0;
	position = *pos;
	while (position[i] && position[i][0] != ';' && position[i][0] != '|')
	{
		i++;
	}
	if (position[i] && position[i][0] == '|')
		cmd->pipe = 1;
	ret = malloc(sizeof(char *) * (i + 1));
	ret[i] = 0;
	i = 0;
	while (position[i] && position[i][0] != ';' && position[i][0] != '|')
	{
		ret[i] = ft_strdup(position[i]);
		i++;
	}
	*pos += i + 1;
	return (ret);
}

void	work_command(t_all *all, t_tokens *tkn, struct termios *old)
{
	t_cmd	cmd;
	char	**position;
	pid_t	pid;

	kill_new_terminal(old);
	init_cmd(&cmd);
	all->all_args = convert_tkn(tkn);
	if (check_dots(all->all_args) == 0 || check_pipes(all->all_args) == 0)
		return ;
	all->dots = find_dots(all->all_args);
	position = all->all_args;
	while (all->dots--)
	{
		all->args = set_args(&position, &cmd);
		if (!(parse_args(all, &cmd, all->args)))
			return ;
		get_args(all->args, &cmd);
		if (cmd.pipe)
		{
			pid = fork();
			if (pid == 0)
			{
				cmd.pipe = 0;
				cmd.pipe_in = 1;
				dup2(cmd.fds[0], 0);
				close(cmd.fds[1]);
				continue ;
			}
		}
		if (is_builtin(&cmd))
			find_cmd(all, &cmd);
		else
			my_execve(all, cmd.args, &cmd);
		free_split(all->args);
		free_cmd(&cmd);
		if (cmd.pipe)
		{
			close(cmd.fds[0]);
			close(cmd.fds[1]);
			waitpid(pid, &all->exit_status, 0);
			break ;
		}
	}
	if (cmd.pipe_in)
		exit(all->exit_status);
}
