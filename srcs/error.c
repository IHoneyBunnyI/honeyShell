#include "minishell.h"

int	exit_term_main(struct termios *old, char *buf)
{
	(void)old;
	/*ft_putstr(tgetstr("ke", 0));*/
	/*tcsetattr(0, TCSANOW, old);*/
	/*printf("\n");*/
	free(buf);
	return (0);
}

void	error(int id, struct termios *old, char *buf)
{
	if (id == 0)
		printf("OK\n");
	else if (id == 1)
		printf("\033[31mERROR: invalid argument\033[0m\n");
	exit_term_main(old, buf);
	exit(1);
}
