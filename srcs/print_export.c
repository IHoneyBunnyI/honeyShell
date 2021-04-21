/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_export.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvernon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 18:44:17 by rvernon           #+#    #+#             */
/*   Updated: 2021/04/21 13:39:57 by rvernon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**sort_env(char **env)
{
	int		i;
	int		j;
	char	*tmp;

	i = 0;
	while (env[i])
	{
		j = 0;
		while (j < i)
		{
			if (ft_strcmp(env[i], env[j]) < 0)
			{
				tmp = env[i];
				env[i] = env[j];
				env[j] = tmp;
			}
			j++;
		}
		i++;
	}
	return (env);
}

char	**copy_env(char **env)
{
	int		i;
	char	**for_sort;

	i = 0;
	while (env[i])
		i++;
	for_sort = malloc(sizeof(char *) * (i + 1));
	if (!for_sort)
		exit(0);
	for_sort[i] = 0;
	while (i--)
	{
		for_sort[i] = ft_strdup(env[i]);
	}
	return (for_sort);
}

void	print_export(char **env, int fd)
{
	int		i;
	char	**print_env;

	i = 0;
	print_env = copy_env(env);
	print_env = sort_env(print_env);
	while (print_env[i])
	{
		ft_putstr_fd("declare -x ", fd);
		ft_putstr_fd(print_env[i], fd);
		ft_putendl_fd("\"", fd);
		i++;
	}
	free_split(print_env);
}
