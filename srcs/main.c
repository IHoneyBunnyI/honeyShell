#include "minishell.h"

int	main(int ac, char **av, char **env)
{
	t_all			all;
	struct termios	old;
	t_ar			ar;
	char			*buf;

	init_all(&ar, &old, &buf, &all);
	if (ac == 1)
	{
		av_env_copy(&all, av, env);
		start(&ar, buf, &all, env);
	}
	else
		error(1, &old, buf);
	return (exit_term(&old, buf));
}
