/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_bX.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvernon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/13 15:19:21 by rvernon           #+#    #+#             */
/*   Updated: 2021/02/14 14:52:36 by rvernon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

char		*ft_forbig(char *s)
{
	int i;

	i = 0;
	while (s && s[i])
	{
		s[i] = ft_toupper(s[i]);
		i++;
	}
	return (s);
}

void		ft_print_bx(t_format *flags, va_list argp)
{
	unsigned int	d;
	char			*s;

	d = va_arg(argp, unsigned int);
	s = ft_itoa_base(d, 16);
	s = ft_forbig(s);
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
