#include "minishell.h"

int	g_state;

void	start(t_ar *ar, char *buf, t_all *all, char **env)
{
	char			c[5];
	t_tokens		*tkn;
	struct termios	old;

	while (ft_strcmp(c, "\4"))
	{
		init_term(&old);
		tputs(save_cursor, 1, ft_putint);
		ft_putstr("🚀 $ ");
		while (1)
		{
			g_state = 0;
			ar->r = read(0, c, 10);
			c[ar->r] = 0;
			if (g_state == 2)
			{
				ar->n = 0;
				g_state = 0;
				ft_putstr("\n");
			}
			if (check_key(c))
				make_key(c, ar, &buf);
			else if (!ft_strcmp(c, "\4") && !ar->n)
				break ;
			else
				write_buf(buf, ar, c);
			if (!ft_strcmp(c, "\n"))
			{
				tkn = next_command(buf, ar, env, all);
				if (!tkn)
					break ;
				g_state = 1;
				work_command(all, tkn, &old);
				break ;
			}
		}
	}
}
