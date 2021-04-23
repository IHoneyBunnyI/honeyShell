#include "minishell.h"

void	error(int id, struct termios *old, char *buf)
{
	if (id == 0)
		printf("OK\n");
	else if (id == 1)
		printf("\033[31mERROR: invalid argument\033[0m\n");
	exit_term(old, buf);
	exit(1);
}
