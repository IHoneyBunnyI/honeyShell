/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arrow.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchaya <mchaya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 14:33:09 by mchaya            #+#    #+#             */
/*   Updated: 2021/03/25 17:59:59 by mchaya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <termios.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <term.h>
#include <curses.h>
#include <sys/ioctl.h>
#include <stdlib.h>
#include "libft.h"

int ft_putint(int c)
{
	return (write(1, &c, 1));
}

int ft_putstr(char *c)
{
	return (write(1, c, ft_strlen(c)));
}

int main() 
{
	struct termios new;
	char c[500];
	int n;

	tcgetattr(0, &new);
	new.c_lflag &= ~(ECHO);
	new.c_lflag &= ~(ICANON);
	tcsetattr(0, TCSANOW, &new);
	tgetent(0, getenv("TERM"));
	ft_putstr(tgetstr("ks", 0));
	ft_putstr(tgetstr("im", 0));
	printf("%s\n", tigetstr("ed"));
	printf("%s\n", tgetstr("dm", 0));
	while (ft_strcmp(c, "\4"))
	{
		tputs(save_cursor, 1, ft_putint);
		while (1)
		{
//			ioctl(0, FIONREAD, &n);
			int r = read(0, c, 100);
			c[r] = 0;
			if (!ft_strcmp(c, tgetstr("ku", 0)))
			{
				tputs(restore_cursor, 1, ft_putint);
				tputs(tigetstr("ed"), 1, ft_putint);
				write(1, "previous", 8);
			}
			else if (!ft_strcmp(c, tgetstr("kd", 0)))
			{
				tputs(restore_cursor, 1, ft_putint);
				tputs(tigetstr("ed"), 1, ft_putint);
				write(1, "next", 4);
			}
			else if (!ft_strcmp(c, "\177"))
			{
				tputs(cursor_left, 1, ft_putint);
				tputs(tgetstr("dc", 0), 1, ft_putint);
			}
			else if (!ft_strcmp(c, tgetstr("kl", 0)))
				tputs(cursor_left, 1, ft_putint);
			else if (!ft_strcmp(c, tgetstr("kr", 0)))
				tputs(cursor_right, 1, ft_putint);
			else
				write(1, c, r);
			if (!ft_strcmp(c, "\n") || !ft_strcmp(c, "\4"))
				break;
		}
	}
	printf("\n");
	return 0;
}

void	exit_terminal(void)
{
	ft_putstr(tgetstr("ke", 0));
	ft_putstr(tgetstr("ei", 0));
}
