/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchaya <mchaya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 16:39:15 by mchaya            #+#    #+#             */
/*   Updated: 2021/04/21 16:39:15 by mchaya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	init_ar(t_ar *ar)
{
	ar->size = 0;
	ar->i = 0;
	ar->n = 0;
}

void	init_all(t_ar *ar, struct termios *old, char **buf)
{
	init_ar(ar);
	init_term(old);
	*buf = malloc(4000 * 1000);
}

void	write_buf(char *buf, t_ar *ar, char *c)
{
	write(1, c, ar->r);
	if (ft_strcmp(c, "\n") && ft_strcmp(c, "\4"))
		buf[ar->size * 4000 + ar->n++] = *c;
}
