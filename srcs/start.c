/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvernon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 12:28:35 by rvernon           #+#    #+#             */
/*   Updated: 2021/03/25 13:20:43 by rvernon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	init_const(t_all *all)
{
	all->start_line = ft_strdup("🚀 $ ");
}

void	loop(t_all *all)
{
	int read;
	char *line = 0;
	char **split;

	read = 1;
	while (read)
	{
		write_start_line(all->start_line);
		read = get_next_line(0, &line);
		if ((ft_strcmp(line, "env")) == 0)
			env(all->env);
		if (line[0] == 'e' && line[1] == 'c' && line[2] == 'h' && line[3] == 'o')
		{
			line = line + 4;
			split = ft_split(line, ' ');
			my_echo(split);
		}
		else if (line[0] == 'p' && line[1] == 'w' && line[2] == 'd')
		{
			pwd();
		}
		//free(line);
	}
}

void	termcap(t_all *all)
{
	char *term;
	(void)all;

	term = getenv("TERM");
	printf("%s\n", term);
}

void	start(t_all *all, char **env)
{
	env_copy(all, env);
	init_const(all);
	termcap(all);
	loop(all);
}

