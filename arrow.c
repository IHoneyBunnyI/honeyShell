/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arrow.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchaya <mchaya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 14:33:09 by mchaya            #+#    #+#             */
/*   Updated: 2021/03/24 14:33:09 by mchaya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <termios.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <term.h>
#include <stdlib.h>

int main() 
{
	struct termios new;
	char c[500];
	char *term_name = "xterm-256color";
	char *str_up;
	char *str_down;

	tcgetattr(0, &new);
	new.c_lflag &= ~(ECHO);
	new.c_lflag &= ~(ICANON);
	tcsetattr(0, TCSANOW, &new);
	printf("%d\n", tgetent(0, term_name));
	str_up = tgetstr("ku", 0);
	str_down = tgetstr("kd", 0);
	while (1)
	{
		int r = read(0, c, 100);
		c[r] = 0;
		write(1, c, r);
		if (!strcmp(c, "\e[A"))
			printf("previous\n");
		else if (!strcmp(c, "\e[B"))
			printf("next\n");
//		else
//			printf("%s\n", c);
		if (*c == 'q')
			break;
//			return (0);
	}
}
