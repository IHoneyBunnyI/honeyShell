#include "minishell.h"

void	init_ar(t_ar *ar)
{
	ar->size = 0;
	ar->i = 0;
	ar->n = 0;
}


void	write_buf(char *buf, t_ar *ar, char *c)
{
	write(1, c, ar->r);
	if (ft_strcmp(c, "\n") && ft_strcmp(c, "\4"))
		buf[ar->size * 4000 + ar->n++] = *c;
}
