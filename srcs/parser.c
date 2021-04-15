/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvernon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 14:07:24 by rvernon           #+#    #+#             */
/*   Updated: 2021/04/15 08:05:45 by rvernon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	find_len_command(char *line)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	while (line[i] != ' ' && line[i] != '\0')
	{
		if (line[i] != '\'' && line[i] != '"')
			len++;
		i++;
	}
	return (len);
}

void	get_line_command(t_all *all, char *line, int len)
{
	int	i;

	i = 0;
	all->command = malloc(sizeof(char) * (len + 1));
	while (line[i])
	{
		if (line[i] == '"')
			i++;
		else
		{
			all->command[i] = line[i];
			i++;
		}
	}
	all->command[i] = 0;
}

void	get_command(t_all *all, char *line)
{
	int	len;

	(void)all;
	len = find_len_command(line);
	get_line_command(all, line, len);
}

void	parser(t_all *all, char *line)
{
	get_command(all, line);
}
