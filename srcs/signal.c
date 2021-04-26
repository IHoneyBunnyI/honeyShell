#include "minishell.h"

void	func(int i)
{
	if (g_state == 1)
		printf("Quit: %d\n", i);
}

