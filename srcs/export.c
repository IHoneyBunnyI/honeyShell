/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvernon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 19:01:00 by rvernon           #+#    #+#             */
/*   Updated: 2021/04/05 20:31:09 by rvernon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	print_export(char **env)
{
	int i;

	i = 0;
	while (env[i])
	{
		printf("%d declare -x %s\"\n",i + 1, env[i]);
		i++;
	}
}

int		find_equal(char *line)
{
	int i;

	i = 0;
	while (line[i])
	{
		if (line[i] == '=')
			return (1);
	}
	return (0);
}

int		num_of_split(char **split)
{
	int i;

	i = 0;
	while (split[i])
		i++;
	return (i);
}

void	free_split(char **split)
{
	int i;
	
	i = 0;
	while (split[i])
		free(split[i++]);
	free(split);
}

void	add_sort_env(t_all *all, char **args)
{
	int i;
	int j;

	i = num_of_split(all->sort_env);
	j = num_of_split(args);
	printf("%d %d\n", j, i);
}

void	export(t_all *all, char **env, char **args)
{
	int i;

	i = 0;
	(void)env;
	while (args[i])
		i++;
	if (i == 1)
		print_export(all->sort_env);
	else
		add_sort_env(all, args + 1);
}
