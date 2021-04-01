/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvernon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 14:04:46 by rvernon           #+#    #+#             */
/*   Updated: 2021/04/01 20:00:25 by rvernon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	av_env_copy(t_all *all, char **av, char **env)
{
	int i;
	
	i = 0;
	while (env[i])
		i++;
	if (!(all->env = malloc(sizeof(char *) * (i + 1))))
		error(1);
	all->env[i] = 0;
	while (i--)
		all->env[i] = ft_strdup(env[i]);
	i = 0;
	while (av[i])
		i++;
	if (!(all->av = malloc(sizeof(char *) * (i + 1))))
		error(1);
	all->av[i] = 0;
	while (i--)
		all->av[i] = ft_strdup(av[i]);
}

int		main(int ac, char **av, char **env)
{
	t_all all;

	(void)av;
	init_all(&all);
	if (ac == 1)
		start(&all, av, env);
	else
		error(1);
}
