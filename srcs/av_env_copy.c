/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   av_env_copy.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvernon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 15:13:30 by rvernon           #+#    #+#             */
/*   Updated: 2021/04/02 22:58:10 by kasimbayb        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
void	param_copy(t_all *all, char **av, char **env)
{
	int i;
	
	i = 0;
	while (av[i])
		i++;
	if (!(all->av = malloc(sizeof(char *) * (i + 1))))
		error(1);
	all->av[i] = 0;
	while (i--)
		all->av[i] = ft_strdup(av[i]);
	i = 0;
	while (env[i])
		i++;
	if (!(all->env = malloc(sizeof(char *) * (i + 1))))
		error(1);
	all->env[i] = 0;
	while (i--)
		all->env[i] = ft_strdup(env[i]);
}

void	av_env_copy(t_all *all, char **av, char **env)
{
	param_copy(all, av, env);
}
