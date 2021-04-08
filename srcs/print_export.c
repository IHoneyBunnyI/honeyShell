/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_export.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvernon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 18:44:17 by rvernon           #+#    #+#             */
/*   Updated: 2021/04/08 19:04:40 by rvernon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char **sort_env(char **env)
{
	int i;
	int j;
	char *tmp;

	i = 0;
	while(env[i])
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

void	print_export(char **env)
{
	int i;
	char **print_env;

	i = 0;
	print_env = sort_env(env);
	while (env[i])
	{
		printf("declare -x %s\"\n", env[i]);
		i++;
	}
}
