/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvernon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 12:28:35 by rvernon           #+#    #+#             */
/*   Updated: 2021/03/24 17:19:44 by rvernon          ###   ########.fr       */
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
		free(line);
		if (line[0] == 'e' && line[1] == 'c' && line[2] == 'h' && line[3] == 'o')
		{
			line = line + 4;
			split = ft_split(line, ' ');
			echo(split);
		}
	}
}

void	start(t_all *all, char **env)
{
	env_copy(all, env);
	init_const(all);
	loop(all);
}

