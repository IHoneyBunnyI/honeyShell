/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   av_env_copy.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvernon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 15:13:30 by rvernon           #+#    #+#             */
/*   Updated: 2021/04/02 15:29:19 by rvernon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
void	param_copy(char **to, char **from)
{
	int i;
	
	i = 0;
	(void)to;
	while (from[i])
	{
		printf("%s\n", from[i]);
		i++;
	}
	/*while (from[i])*/
		/*i++;*/
	/*if (!(to = malloc(sizeof(char *) * (i + 1))))*/
		/*error(1);*/
	/*to[i] = 0;*/
	/*while (i--)*/
		/*to[i] = ft_strdup(from[i]);*/
}

void	av_env_copy(t_all *all, char **av, char **env)
{
	param_copy(all->env, env);
	param_copy(all->av, av);
}
