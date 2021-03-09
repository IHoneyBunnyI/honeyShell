/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_u.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvernon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/13 14:12:49 by rvernon           #+#    #+#             */
/*   Updated: 2020/12/13 17:31:31 by rvernon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

void		ft_print_u(t_format *flags, va_list argp)
{
	unsigned int	d;
	char			*s;

	d = va_arg(argp, unsigned int);
	s = ft_itoa(d);
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
