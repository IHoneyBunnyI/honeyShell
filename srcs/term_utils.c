/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   term_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchaya <mchaya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 12:26:33 by mchaya            #+#    #+#             */
/*   Updated: 2021/04/19 12:26:46 by mchaya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	make_keyup(char *sbuf, char *ibuf)
{
	int	n;
	int	k;

	k = tgetnum("co");
	n = ft_strlen(ibuf + 4000) / k;
	tputs(restore_cursor, 1, ft_putint);
	while (n > 0)
	{
		tputs(tgetstr("dl", 0), 1, ft_putint);
		n--;
	}
	tputs(tgetstr("dl", 0), 1, ft_putint);
	ft_putstr("🚀 $ ");
	ft_strlcpy(sbuf, ibuf, ft_strlen(ibuf) + 1);
	write(1, sbuf, ft_strlen(sbuf));
	return (ft_strlen(sbuf));
}

int	make_keydown(char *buf, int size, int i)
{
	int	n;
	int	k;

	k = tgetnum("co");
	n = ft_strlen(buf + (i - 1) * 4000) / k;
	tputs(restore_cursor, 1, ft_putint);
	while (n >= 1)
	{
		tputs(tgetstr("dl", 0), 1, ft_putint);
		n--;
	}
	tputs(tgetstr("dl", 0), 1, ft_putint);
	if (i == size)
		buf[i * 4000] = 0;
	ft_putstr("🚀 $ ");
	ft_strlcpy(buf + size * 4000, buf + i * 4000,
			   ft_strlen(buf + i * 4000) + 1);
	write(1, buf + size * 4000, ft_strlen(buf + size * 4000));
	return (ft_strlen(buf + size * 4000));
}