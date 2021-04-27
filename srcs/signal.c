#include "minishell.h"

void	func(int i)
{
	i = 12345678;
}

void	sig_c(int i)
{
	struct termios	old;
	struct termios	new;

	tcgetattr(0, &old);
	new = old;
	new.c_lflag &= ~(ICANON | ECHO);
	tcsetattr(0, TCSANOW, &new);
	if (g_state != 1)
		ft_putstr("\n🚀 $ ");
	else
		ft_putstr("\n");
	g_state = 2;
}
