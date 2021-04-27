#include "minishell.h"

int	make_keyup(char *sbuf, char *ibuf)
{
	int	n;
	int	k;

	k = tgetnum("co");
	n = ft_strlen(ibuf + 4000) / k;
	tputs(restore_cursor, 1, ft_putint);
	while (n > 0)
	{
		tputs(tgetstr("dl", 0), 1, ft_putint);
		n--;
	}
	tputs(tgetstr("dl", 0), 1, ft_putint);
	ft_putstr("🚀 $ ");
	ft_strlcpy(sbuf, ibuf, ft_strlen(ibuf) + 1);
	write(1, sbuf, ft_strlen(sbuf));
	return (ft_strlen(sbuf));
}

int	make_keydown(char *buf, int size, int i)
{
	int	n;
	int	k;

	k = tgetnum("co");
	n = ft_strlen(buf + (i - 1) * 4000) / k;
	tputs(restore_cursor, 1, ft_putint);
	while (n >= 1)
	{
		tputs(tgetstr("dl", 0), 1, ft_putint);
		n--;
	}
	tputs(tgetstr("dl", 0), 1, ft_putint);
	if (i == size)
		buf[i * 4000] = 0;
	ft_putstr("🚀 $ ");
	ft_strlcpy(buf + size * 4000, buf + i * 4000,
		ft_strlen(buf + i * 4000) + 1);
	write(1, buf + size * 4000, ft_strlen(buf + size * 4000));
	return (ft_strlen(buf + size * 4000));
}

int	check_key(char *c)
{
	if (!ft_strcmp(c, tgetstr("ku", 0)))
		return (1);
	else if (!ft_strcmp(c, tgetstr("kd", 0)))
		return (1);
	else if (!ft_strcmp(c, "\177"))
		return (1);
	else if (!ft_strcmp(c, tgetstr("kl", 0)) || !ft_strcmp(c,
			tgetstr("kr", 0)))
		return (1);
	return (0);
}

void	make_key(char *c, t_ar *ar, char **buf)
{
	if (!ft_strcmp(c, tgetstr("ku", 0)))
	{
		if (ar->i)
			ar->n = make_keyup(*buf + ar->size * 4000, *buf + --ar->i
					* 4000);
	}
	else if (!ft_strcmp(c, tgetstr("kd", 0)))
	{
		if (ar->i < ar->size)
			ar->n = make_keydown(*buf, ar->size, ++ar->i);
	}
	else if (!ft_strcmp(c, "\177"))
	{
		if (ar->n)
			make_bs(&ar->n);
	}
	else if (!ft_strcmp(c, tgetstr("kl", 0)) || !ft_strcmp(c,
			tgetstr("kr", 0)))
		make_lr(c, &ar->n, *buf, ar->size);
}

int	exit_term(/*struct termios *old,*/ char *buf)
{
	ft_putstr("exit\n");
	//ft_putstr(tgetstr("ke", 0));
	//tcsetattr(0, TCSANOW, old);
	//printf("\n");
	free(buf);
	return (0);
}
