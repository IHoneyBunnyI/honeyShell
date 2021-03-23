/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvernon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 14:04:46 by rvernon           #+#    #+#             */
/*   Updated: 2021/03/23 19:07:37 by rvernon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		env(char **s)
{
	int i;

	i = -1;
	while (s[++i])
	{
		printf("%s\n", s[i]);
	}
	return (0);
}

void	loop(char **e)
{
	int read;
	char *line = 0;

	read = 1;
	while (read)
	{
		write(2, "Баш коронный, шел похоронный $: ", ft_strlen("Баш коронный, шел похоронный $: "));
		read = get_next_line(0, &line);
		printf("%s\n", line);
		if ((ft_strcmp(line, "env")) == 0)
		{
			env(e);
		}
		free(line);
	}
}

int		main(int ac, char **av, char **env)
{
	(void)ac;
	(void)av;
	(void)env;
	loop(env);
}
