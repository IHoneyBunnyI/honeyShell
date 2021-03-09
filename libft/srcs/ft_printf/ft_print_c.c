/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prints.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvernon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/06 14:07:16 by rvernon           #+#    #+#             */
/*   Updated: 2020/12/09 21:09:45 by rvernon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

void	ft_print_c(t_format *flags, va_list argp)
{
	char	c;
	int		i;

	i = -1;
	c = va_arg(argp, int);
	if (flags->minus)
	{
		write(1, &c, 1);
		while (++i < flags->width - 1)
		{
			write(1, " ", 1);
			flags->length += 1;
		}
	}
	else if (!flags->minus)
	{
		while (++i < flags->width - 1)
		{
			ft_write(" ", 1, flags);
		}
		write(1, &c, 1);
	}
	flags->length += 1;
}
