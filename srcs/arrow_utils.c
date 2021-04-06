/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arrow_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchaya <mchaya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 11:26:14 by mchaya            #+#    #+#             */
/*   Updated: 2021/04/06 11:35:00 by mchaya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int ft_putint(int c)
{
	return (write(1, &c, 1));
}

int ft_putstr(char *c)
{
	return (write(1, c, ft_strlen(c)));
}

void	make_lr(char *c, int *n, char *buf, int size)
{
	if (!ft_strcmp(c, tgetstr("kl", 0)))
	{
		if (*n)
		{
			tputs(cursor_left, 1, ft_putint);
			(*n)--;
		}
	}
	else if (!ft_strcmp(c, tgetstr("kr", 0)))
	{
		if (*n < ft_strlen(buf + size * 4000))
		{
			tputs(cursor_right, 1, ft_putint);
			(*n)++;
		}
	}
}