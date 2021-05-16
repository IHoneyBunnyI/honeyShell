#include "minishell.h"

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

void	close_wait_if_pid(t_all *all, t_cmd *cmd, pid_t pid)
{
	close(cmd->fds[0]);
	close(cmd->fds[1]);
	waitpid(pid, &all->exit_status, 0);
}

void	exec_or_built(t_all *all, t_cmd *cmd)
{
	if (is_builtin(cmd))
		find_cmd(all, cmd);
	else
		my_execve(all, cmd->args, cmd);
	free_split(all->args);
	free_cmd(cmd);
}

void	work_next_command(t_all *all, t_cmd *cmd, char **position)
{
	pid_t	pid;

	while (all->dots--)
	{
		all->args = set_args(&position, cmd);
		if (!(parse_args(all, cmd, all->args)))
			return ;
		get_args(all->args, cmd);
		if (cmd->pipe)
		{
			pid = fork();
			if (pid == 0)
			{
				if_pid_o(cmd);
				continue ;
			}
		}
		exec_or_built(all, cmd);
		if (cmd->pipe)
		{
			close_wait_if_pid(all, cmd, pid);
			break ;
		}
	}
}

void	work_command(t_all *all, t_tokens *tkn, struct termios *old)
{
	t_cmd	cmd;
	char	**position;

	kill_new_terminal(old);
	init_cmd(&cmd);
	all->all_args = convert_tkn(tkn);
	if (check_dots(all->all_args) == 0 || check_pipes(all->all_args) == 0)
		return ;
	all->dots = find_dots(all->all_args);
	position = all->all_args;
	work_next_command(all, &cmd, position);
	if (cmd.pipe_in)
		exit(all->exit_status);
}
