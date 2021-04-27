#include "minishell.h"

int	main(int ac, char **av, char **env)
{
	t_all			all;
	struct termios	old;
	t_ar			ar;
	char			*buf;

	signal(SIGQUIT, func);
	signal(SIGINT, sig_c);
	g_state = 0;
	init_all(&ar, &buf, &all);
	if (ac == 1)
	{
		av_env_copy(&all, av, env);
		start(&ar, buf, &all);
	}
	else
		error(1, &old, buf);
	return (exit_term(buf));
}
