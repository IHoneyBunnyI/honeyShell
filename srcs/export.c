/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvernon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 19:01:00 by rvernon           #+#    #+#             */
/*   Updated: 2021/04/03 17:37:11 by rvernon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	print_export(char **env)
{
	int i;

	i = 0;
	while (env[i])
	{
		printf("declare -x %s\"\n", env[i]);
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

void	add_sort_env(t_all *all, char *line)
{
	(void)all;
	(void)line;
}

void	export(t_all *all, char **env, char **args)
{
	int i;

	i = 0;
	while (args[i])
		i++;
	if (i == 1)
		print_export(env);
	else
	{
		if ((find_equal(args[i])) == 0)
			add_sort_env(all, args[i]);
	}
}
