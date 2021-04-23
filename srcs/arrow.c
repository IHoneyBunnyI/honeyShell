#include "minishell.h"

t_tokens	*next_command(char *buf, t_ar *ar)
{
	t_tokens	*tkn;

	buf[ar->size * 4000 + ar->n] = 0;
	tkn = flexer(buf + (ar->size * 4000));
	if (buf[ar->size * 4000])
	{
		if (ar->size < 1000)
			(ar->size)++;
		ar->i = ar->size;
		buf[ar->size * 4000] = 0;
	}
	ar->n = 0;
	return (tkn);
}
