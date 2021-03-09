/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_x.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvernon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/13 14:07:34 by rvernon           #+#    #+#             */
/*   Updated: 2020/12/13 19:49:57 by rvernon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

void		ft_print_x(t_format *flags, va_list argp)
{
	unsigned int	d;
	char			*s;

	d = va_arg(argp, unsigned int);
	s = ft_itoa_base(d, 16);
	if (flags->isaccuracy && flags->accuracy <= 0 && d == 0)
		print_d_null_null(flags);
	else if (!flags->minus && !flags->null)
		print_d_without(flags, s);
	else if (flags->minus)
		print_d_minus(flags, s);
	else if (flags->null)
		print_d_null(flags, s);
	free(s);
}
