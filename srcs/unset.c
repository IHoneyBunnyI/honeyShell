/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvernon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 17:57:21 by rvernon           #+#    #+#             */
/*   Updated: 2021/04/13 20:58:31 by kasimbayb        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		find_name(t_all *all, char *arg)
{
	return (1);
}

void	del_arg(t_all *all, char *arg)
{
	;
}

void	unset(t_all *all, char **args)
{
	int i;

	i = 0;
	while (args[i])
	{
		if (find_name(all, args[i]))
			del_arg(all, args[i]);
	}
}
