/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvernon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 19:01:00 by rvernon           #+#    #+#             */
/*   Updated: 2021/04/15 11:35:24 by rvernon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	find_equal(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] == '=')
			return (1);
	}
	return (0);
}

int	num_of_split(char **split)
{
	int	i;

	i = 0;
	while (split[i])
		i++;
	return (i);
}

void	free_split(char **split)
{
	int	i;

	i = 0;
	while (split[i])
		free(split[i++]);
	free(split);
}

void	copy_args(t_all *all, char **new_env, char **arg)
{
	*new_env = ft_strdup(*arg);
	(void)all;
}

void	add_sort_env(t_all *all, char **args)
{
	int		i;
	int		j;
	char	**new_env;

	i = num_of_split(all->env);
	j = num_of_split(args);
	new_env = malloc(sizeof(char *) * (i + j + 1));
	new_env[i + j] = 0;
	j = -1;
	i = -1;
	while (args[++j])
		copy_args(all, &new_env[j], &args[j]);
	while (all->env[++i])
		new_env[j + i] = all->env[i];
	free(all->env);
	all->env = new_env;
}

void	export(t_all *all, char **env, char **args)
{
	int	i;

	i = 0;
	(void)env;
	while (args[i])
		i++;
	if (i == 1)
		print_export(all->env);
	else
		add_sort_env(all, args + 1);
}
