/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvernon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 12:28:35 by rvernon           #+#    #+#             */
/*   Updated: 2021/04/15 09:41:39 by rvernon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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

void	my_execve(t_all *all, char **args)
{
	char	*bin;
	pid_t	pid;

	bin = ft_strdup("/bin/");
	bin = ft_strjoin(bin, args[0]);
	pid = fork();
	waitpid(pid, 0, 0);
	if (pid == 0)
	{
		execve(bin, all->args, all->env);
		exit(0);
	}
	free(bin);
}

void	easy_parser(t_all *all, char *l)
{
	all->args = ft_split(l, ' ');
	if (is_echo(l))
		my_echo(all->args + 1);
	else if (l[0] == 'e' && l[1] == 'n' && l[2] == 'v')
		env(all->env);
	else if (l[0] == 'p' && l[1] == 'w' && l[2] == 'd')
		pwd();
	else if (l[0] == 'e' && l[1] == 'x' && l[2] == 'p' && \
			 l[3] == 'o' && l[4] == 'r' && l[5] == 't' )
		export(all, all->env, all->args);
	else if (l[0] == 'u' && l[1] == 'n' && l[2] == 's' && \
			 l[3] == 'e' && l[4] == 't')
		my_unset(all, all->args + 1);
	else if (l[0] == 'c' && l[1] == 'd')
		cd(all, all->args);
	else
		my_execve(all, all->args);
	free_split(all->args);
}

void	loop(t_all *all)
{
	int		read;
	char	*line;

	line = 0;
	read = 1;
	while (read)
	{
		write_start_line(all->start_line);
		read = get_next_line(0, &line);
		easy_parser(all, line);
		free(line);
	}
}

void	termcap(t_all *all)
{
	char			*term;
	struct termios	new;
	struct termios	old;

	(void)all;
	(void)new;
	(void)old;
	term = getenv("TERM");
}

void	start(t_all *all, char **av, char **env)
{
	av_env_copy(all, av, env);
	init_const(all);
	termcap(all);
	loop(all);
}
