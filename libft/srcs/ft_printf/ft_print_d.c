/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_d.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvernon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/09 21:08:40 by rvernon           #+#    #+#             */
/*   Updated: 2020/12/13 20:20:53 by rvernon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

void		print_d_null_min(t_format *flags, char *s)
{
	if (flags->isaccuracy && flags->accuracy > ft_strlen(s))
	{
		ft_write(" ", flags->width - flags->accuracy - 1, flags);
		ft_write("-", 1, flags);
		ft_write("0", flags->accuracy - ft_strlen(s), flags);
		ft_write(s, ft_strlen(s), flags);
	}
	if (flags->isaccuracy && flags->accuracy <= ft_strlen(s))
	{
		ft_write(" ", flags->width - ft_strlen(s) - 1, flags);
		ft_write("-", 1, flags);
		ft_write(s, ft_strlen(s), flags);
	}
	if (!flags->isaccuracy)
	{
		ft_write("-", 1, flags);
		ft_write("0", flags->width - ft_strlen(s) - 1, flags);
		ft_write(s, ft_strlen(s), flags);
	}
}

void		print_d_without(t_format *flags, char *s)
{
	if (flags->isaccuracy && flags->accuracy > ft_strlen(s))
	{
		ft_write(" ", flags->width - flags->accuracy, flags);
		ft_write("0", flags->accuracy - ft_strlen(s), flags);
		ft_write(s, ft_strlen(s), flags);
	}
	if (!flags->accuracy || (flags->isaccuracy &&
				flags->accuracy <= ft_strlen(s)))
	{
		ft_write(" ", flags->width - ft_strlen(s), flags);
		ft_write(s, ft_strlen(s), flags);
	}
}

void		print_d_without_min(t_format *flags, char *s)
{
	if (flags->isaccuracy && flags->accuracy > ft_strlen(s))
	{
		ft_write(" ", flags->width - flags->accuracy - 1, flags);
		ft_write("-", 1, flags);
		ft_write("0", flags->accuracy - ft_strlen(s), flags);
		ft_write(s, ft_strlen(s), flags);
	}
	if (!flags->isaccuracy || (flags->isaccuracy &&
				flags->accuracy <= ft_strlen(s)))
	{
		ft_write(" ", flags->width - ft_strlen(s) - 1, flags);
		ft_write("-", 1, flags);
		ft_write(s, ft_strlen(s), flags);
	}
}

void		print_d_null_null(t_format *flags)
{
	ft_write(" ", flags->width, flags);
}

void		ft_print_d(t_format *flags, va_list argp)
{
	int		d;
	int		sign;
	char	*s;

	d = va_arg(argp, int);
	sign = d < 0 ? 1 : 0;
	d = d < 0 ? -d : d;
	s = ft_itoa(d);
	if (flags->isaccuracy && flags->accuracy <= 0 && d == 0)
		print_d_null_null(flags);
	else if (!flags->minus && !flags->null && !sign)
		print_d_without(flags, s);
	else if (!flags->minus && !flags->null && sign)
		print_d_without_min(flags, s);
	else if (flags->minus && !sign)
		print_d_minus(flags, s);
	else if (flags->minus && sign)
		print_d_minus_min(flags, s);
	else if (flags->null && !sign)
		print_d_null(flags, s);
	else if (flags->null && sign)
		print_d_null_min(flags, s);
	free(s);
}
