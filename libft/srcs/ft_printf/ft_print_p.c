/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_p.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvernon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/09 17:00:48 by rvernon           #+#    #+#             */
/*   Updated: 2020/12/13 19:59:28 by rvernon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

static void		print_p_null_null(t_format *flags)
{
	if (!flags->minus)
	{
		ft_write(" ", flags->width - 2, flags);
		ft_write("0x", 2, flags);
	}
	else
	{
		ft_write("0x", 2, flags);
		ft_write(" ", flags->width - 2, flags);
	}
}

static void		print_p_without(t_format *flags, char *s)
{
	if (flags->isaccuracy && flags->accuracy > ft_strlen(s))
	{
		ft_write(" ", flags->width - flags->accuracy - 2, flags);
		ft_write("0x", 2, flags);
		ft_write("0", flags->accuracy - ft_strlen(s), flags);
		ft_write(s, ft_strlen(s), flags);
	}
	if (!flags->accuracy || (flags->isaccuracy &&
				flags->accuracy <= ft_strlen(s)))
	{
		ft_write(" ", flags->width - ft_strlen(s) - 2, flags);
		ft_write("0x", 2, flags);
		ft_write(s, ft_strlen(s), flags);
	}
}

static void		print_p_minus(t_format *flags, char *s)
{
	if (flags->isaccuracy && flags->accuracy > ft_strlen(s))
	{
		ft_write("0x", 2, flags);
		ft_write("0", flags->accuracy - ft_strlen(s), flags);
		ft_write(s, ft_strlen(s), flags);
		ft_write(" ", flags->width - flags->accuracy - 2, flags);
	}
	if (!flags->accuracy || (flags->isaccuracy &&
				flags->accuracy <= ft_strlen(s)))
	{
		ft_write("0x", 2, flags);
		ft_write(s, ft_strlen(s), flags);
		ft_write(" ", flags->width - ft_strlen(s) - 2, flags);
	}
}

void			ft_print_p(t_format *flags, va_list argp)
{
	unsigned long	long	d;
	char					*s;

	d = va_arg(argp, unsigned long);
	s = ft_itoa_base(d, 16);
	if (flags->isaccuracy && flags->accuracy <= 0 && d == 0)
		print_p_null_null(flags);
	else if (!flags->minus && !flags->null)
		print_p_without(flags, s);
	else if (flags->minus)
		print_p_minus(flags, s);
	else if (flags->null)
		print_p_without(flags, s);
	free(s);
}
