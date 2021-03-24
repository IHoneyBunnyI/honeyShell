/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvernon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 14:04:46 by rvernon           #+#    #+#             */
/*   Updated: 2021/03/24 16:42:31 by rvernon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	loop(t_all *all)
{
	int read;
	char *line = 0;

	read = 1;
	while (read)
	{
		write(2, "🗿🗿🗿🗿🗿$ ", ft_strlen("🗿🗿🗿🗿🗿$ "));
		read = get_next_line(0, &line);
		if ((ft_strcmp(line, "env")) == 0)
			env(all->env);
		free(line);
	}
}

void	env_copy(t_all *all, char **from)
{
	int i;
	
	i = 0;
	while (from[i])
		i++;
	if (!(all->env = malloc(sizeof(char *) * (i + 1))))
		error(1);
	all->env[i] = 0;
	while (i--)
		all->env[i] = ft_strdup(from[i]);
}

int		main(int ac, char **av, char **env)
{
	t_all all;

	(void)av;
	(void)env;
	init_all(&all);
	if (ac == 1)
		start(&all, env);
	else
		error(1);
}
