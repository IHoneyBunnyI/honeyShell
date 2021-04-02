/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   av_env_copy.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvernon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 15:13:30 by rvernon           #+#    #+#             */
/*   Updated: 2021/04/02 23:39:10 by kasimbayb        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	av_copy(t_all *all, char **av)
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
}

int		find_oldpwd(char *line)
{
	if (line[0] == 'O' && line[1] == 'L' && line[2] == 'D' && line[3] == 'P' && line[4] == 'W' && line[5] == 'D')
		return (1);
	return (0);
}

void	env_copy(t_all *all, char **env)
{
	int i;

	i = 0;
	while (env[i])
		i++;
	if (!(all->env = malloc(sizeof(char *) * (i + 1))))
		error(1);
	if (!(all->sort_env = malloc(sizeof(char *) * (i + 1))))
		error(1);
	all->env[i] = 0;
	all->sort_env[i] = 0;
	while (i--)
	{
		if (find_oldpwd(env[i]))
			all->sort_env[i] = ft_strdup("OLDPWD");
		else
		{
			all->env[i] = ft_strdup(env[i]);
			all->sort_env[i] = ft_strdup(env[i]);
		}
	}
}

void	sort_env(t_all *all)
{
	int i;
	int j;
	char *tmp;

	i = 0;
	while(all->sort_env[i])
	{
		j = 0;
		while (j < i)
		{
			if (ft_strcmp(all->sort_env[i], all->sort_env[j]) < 0)
			{
				tmp = all->sort_env[i];
				all->sort_env[i] = all->sort_env[j];
				all->sort_env[j] = tmp;
			}
			j++;
		}
		i++;
	}
}

void	av_env_copy(t_all *all, char **av, char **env)
{
	env_copy(all, env);
	av_copy(all, av);
	sort_env(all);
}
