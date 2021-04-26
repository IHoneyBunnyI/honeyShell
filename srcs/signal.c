#include "minishell.h"

void	func(int i)
{
	if (g_state == 1)
		printf("Quit: %d\n", i);
}

void	sig_c(int i)
{
	i = 0;
	if (g_state != 1)
		ft_putstr("\n🚀 $ ");
	//g_state = 2;

}
