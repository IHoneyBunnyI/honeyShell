/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arrow.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchaya <mchaya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 14:33:09 by mchaya            #+#    #+#             */
/*   Updated: 2021/04/17 15:42:13 by mchaya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

t_tokens	*next_command(char *buf, int *n, int *size, int *i, char **env)
{
	t_tokens	*tkn;

	buf[*size * 4000 + *n] = 0;
	tkn = flexer(buf + (*size * 4000), env);
	if (buf[*size * 4000])
	{
		if (*size < 1000)
			(*size)++;
		*i = *size;
		buf[*size * 4000] = 0;
	}
	*n = 0;
	return (tkn);
}

int	exit_term(struct termios *old, char *buf)
{
	ft_putstr("exit");
	ft_putstr(tgetstr("ke", 0));
	tcsetattr(0, TCSANOW, old);
	printf("\n");
	free(buf);
	return (0);
}

int	main(int argc, char **argv, char **env)
{
	struct termios	old;
	char			c[5];
	char			*buf;
	int				i;
	int				n;
	int				size;
	int				r;
	t_tokens		*tkn;

	i = 0;
	n = 0;
	size = 0;
	init_term(&old);
	buf = malloc(4000 * 1000);
	while (ft_strcmp(c, "\4"))
	{
		tputs(save_cursor, 1, ft_putint);
		ft_putstr("🚀 $ ");
		while (1)
		{
			r = read(0, c, 10);
			c[r] = 0;
			if (!ft_strcmp(c, tgetstr("ku", 0)))
			{
				if (i)
					n = make_keyup(buf + size * 4000, buf + --i * 4000);
			}
			else if (!ft_strcmp(c, tgetstr("kd", 0)))
			{
				if (i < size)
					n = make_keydown(buf, size, ++i);
			}
			else if (!ft_strcmp(c, "\177"))
			{
				if (n)
					make_bs(&n);
			}
			else if (!ft_strcmp(c, tgetstr("kl", 0)) || !ft_strcmp(c,
					tgetstr("kr", 0)))
				make_lr(c, &n, buf, size);
			else if (!ft_strcmp(c, "\4") && !n)
				break ;
			else
			{
				write(1, c, r);
				if (ft_strcmp(c, "\n") && ft_strcmp(c, "\4"))
					buf[size * 4000 + n++] = *c;
			}
			if (!ft_strcmp(c, "\n"))
			{
				tkn = next_command(buf, &n, &size, &i, env);
				while (tkn)
				{
					printf("tk = %s, oprt = %d\n", tkn->token, tkn->is_oprt);
					tkn = tkn->next;
				}
				break ;
			}
		}
	}
	return (exit_term(&old, buf));
}
