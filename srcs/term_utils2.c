#include "minishell.h"

int	exit_term(char *buf)
{
	ft_putstr("exit\n");
	free(buf);
	return (0);
}
