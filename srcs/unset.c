/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvernon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 17:57:21 by rvernon           #+#    #+#             */
/*   Updated: 2021/04/13 23:04:55 by kasimbayb        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		find_arg(char *s1, char *s2)
{
	int i;

	i = 0;
	while (s1[i] != '=' && s1[i])
	{
		if (s1[i] != s2[i])
			return 0;
		i++;
	}
	return 1;
}

int		find_name(t_all *all, char *arg)
{
	(void)all;
	(void)arg;
	int i;

	i = 0;
	while (all->env[i])
	{
		if (find_arg(all->env[i], arg))
			return i + 1;
		i++;
	}
	return (0);
}

char	**del_arg(t_all *all, int index)
{
	char **ret;
	int i;
	int j;

	i = 0;
	j = 0;
	while (all->env[i])
		i++;
	ret = malloc(sizeof(char *) * i);
	ret[--i] = 0;
	i = -1;
	while (all->env[++i])
	{
		if (i != index)
		{
			ret[j++] = all->env[i];
		}
		else
			free(all->env[i]);
	}
	free(all->env);
	return (ret);
}

void	my_unset(t_all *all, char **args)
{
	int i;

	i = -1;
	while (args[++i])
	{
		int index = find_name(all, args[i]);
		if (index != 0)
			printf("FIND = %d\n", --index);
			all->env = del_arg(all, index);
	}
}
