/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arrow.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchaya <mchaya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 14:33:09 by mchaya            #+#    #+#             */
/*   Updated: 2021/04/01 21:28:50 by rvernon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minishell.h"
int ft_putint(int c)
{
	return (write(1, &c, 1));
}
void	exit_terminal(void)
{
	printf("%s", tgetstr("ke", 0));
	printf("%s", tgetstr("ei", 0));
}
int main() 
{
	char c[5];
	char *buf;
	int i;
	int n;
	int size;
	i = 0;
	n = 0;
	size = 0;
	tcgetattr(0, &old);
	new = old;
	new.c_lflag &= ~(ECHO);
	new.c_lflag &= ~(ICANON);
	tcsetattr(0, TCSANOW, &new);
	tgetent(0, getenv("TERM"));
	setvbuf(stdout, NULL, _IONBF, 0);
	printf("%s", tgetstr("ks", 0));
//	tputs(restore_cursor, 1, ft_putint);
//	tputs(tigetstr("ed"), 1, ft_putint);
	printf("%s", tgetstr("im", 0));
	buf = malloc(4000 * 1000);
	while (ft_strcmp(c, "\4"))
	{
		tputs(save_cursor, 1, ft_putint);
		while (1)
		{
//			ioctl(0, FIONREAD, &n);
			int r = read(0, c, 10);
			c[r] = 0;
			int l;
			l = n;
			if (!ft_strcmp(c, tgetstr("ku", 0)))
			{
				if (i)
				{
					tputs(restore_cursor, 1, ft_putint);
					tputs(tgetstr("dl", 0), 1, ft_putint);
					i--;
					ft_strlcpy(buf + size * 4000, buf + i * 4000, ft_strlen
					(buf + i * 4000) + 1);
					write(1, buf + size * 4000, ft_strlen(buf + size * 4000));
					n = ft_strlen(buf + size * 4000);
				}
			}
			else if (!ft_strcmp(c, tgetstr("kd", 0)))
			{
				if (buf[i * 4000] || i + 2 == size)
				{
					tputs(restore_cursor, 1, ft_putint);
					tputs(tgetstr("dl", 0), 1, ft_putint);
					i++;
					ft_strlcpy(buf + size * 4000, buf + i * 4000, ft_strlen(buf + i * 4000) + 1);
					write(1, buf + size * 4000, ft_strlen(buf + size * 4000));
					n = ft_strlen(buf + size * 4000);
				}
			}
			else if (!ft_strcmp(c, "\177"))
			{
				if (n)
				{
					tputs(cursor_left, 1, ft_putint);
					tputs(tgetstr("dc", 0), 1, ft_putint);
					n--;
				}
			}
			else if (!ft_strcmp(c, tgetstr("kl", 0)))
			{
				if (n)
				{
					tputs(cursor_left, 1, ft_putint);
					n--;
				}
			}
			else if (!ft_strcmp(c, tgetstr("kr", 0)))
			{
				int k = n;
				if (k != n)
				{
					tputs(cursor_right, 1, ft_putint);
					n++;
				}
			}
			else
			{
				write(1, c, r);
				if (ft_strcmp(c, "\n"))
					buf[i * 4000 + n++] = *c;
			}
			if (!ft_strcmp(c, "\n") || !ft_strcmp(c, "\4"))
			{
				buf[i * 4000 + n] = 0;
				if (ft_strcmp(buf + (i * 4000), "\n"))
				{
					size++;
					i = size;
					buf[i * 4000] = 0;
				}
				n = 0;
				break;
			}
		}
	}
	printf("%s", tgetstr("ke", 0));
	tcsetattr(0, TCSANOW, &old);
	printf("\n");
	printf("%s", buf + (i - 1) * 4000);
	return 0;
}
