/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvernon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 17:09:41 by rvernon           #+#    #+#             */
/*   Updated: 2021/04/15 13:17:16 by rvernon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	write_start_line(char *line)
{
	int	len;

	len = ft_strlen(line);
	write(2, line, len);
}

void	init_const(t_all *all)
{
	all->start_line = ft_strdup("🚀 $ ");
}

int	is_echo(char *l)
{
	if (l[0] == 'e' && l[1] == 'c' && l[2] == 'h' && l[3] == 'o')
		return (1);
	return (0);
}
