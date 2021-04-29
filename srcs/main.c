#include "minishell.h"

int	main(int ac, char **av, char **env)
{
	t_all			all;
	struct termios	old;
	t_ar			ar;
	char			*buf;
	int				i;

	i = 0;
	signal(SIGQUIT, func);
	signal(SIGINT, sig_c);
	g_state = 0;
	init_all(&ar, &buf, &all);
	if (ac == 1)
	{
		av_env_copy(&all, av, env);
		start(&ar, buf, &all);
		free_split(all.av);
		free_split(all.env);
	}
	else
		error(1, &old, buf);
	return (exit_term(buf));
}
