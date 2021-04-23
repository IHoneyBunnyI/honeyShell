#include "minishell.h"

void	easy_parser(t_all *all, char *l, int fd)
{
	all->args = ft_split(l, ' ');
	if (is_echo(l))
		my_echo(all->args + 1);
	else if (l[0] == 'e' && l[1] == 'n' && l[2] == 'v')
		env(all->env, fd);
	else if (l[0] == 'p' && l[1] == 'w' && l[2] == 'd')
		pwd(fd);
	else if (l[0] == 'e' && l[1] == 'x' && l[2] == 'p' && \
			 l[3] == 'o' && l[4] == 'r' && l[5] == 't' )
		export(all, all->args, fd);
	else if (l[0] == 'u' && l[1] == 'n' && l[2] == 's' && \
			 l[3] == 'e' && l[4] == 't')
		my_unset(all, all->args + 1);
	else if (l[0] == 'c' && l[1] == 'd')
		cd(all, all->args);
	else if (l[0] == 'e' && l[1] == 'x' && l[2] == 'i' && l[3] == 't')
		ft_exit(all->args);
	else if (ft_strcmp(l, "") != 0)
		my_execve(all, all->args, fd);
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
//		read = get_next_line(0, &line);
		int fd = open("test", O_CREAT | O_RDWR, S_IREAD | S_IWRITE | S_IRGRP | S_IROTH);
		if (fd < 0)
			printf("ERR\n");
		easy_parser(all, line, fd);
		close(fd);
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

void	start(t_ar *ar, char *buf, t_all *all)
{
	char			c[5];
	t_tokens		*tkn;

	while (ft_strcmp(c, "\4"))
	{
		tputs(save_cursor, 1, ft_putint);
		ft_putstr("🚀 $ ");
		while (1)
		{
			ar->r = read(0, c, 10);
			c[ar->r] = 0;
			if (check_key(c))
				make_key(c, ar, &buf);
			else if (!ft_strcmp(c, "\4") && !ar->n)
				break ;
			else
				write_buf(buf, ar, c);
			if (!ft_strcmp(c, "\n"))
			{
				tkn = next_command(buf, ar);
				work_command(all, tkn);
				break ;
			}
		}
	}
}
