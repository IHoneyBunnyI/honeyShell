#include "minishell.h"

void	pwd(int fd)
{
	char	*pwd;
	int		len;

	pwd = getcwd(0, 0);
	if (!pwd)
	{
		write(fd, "\n", 1);
		return;
	}
	len = ft_strlen(pwd);
	write(fd, pwd, len);
	write(fd, "\n", 1);
	free(pwd);
}
