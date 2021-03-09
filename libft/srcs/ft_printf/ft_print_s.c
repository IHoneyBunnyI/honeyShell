/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_s.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvernon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/06 17:28:00 by rvernon           #+#    #+#             */
/*   Updated: 2020/12/11 21:27:19 by rvernon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

static void		print_s_minus(t_format *flags, char *s)
{
	if (flags->accuracy <= ft_strlen(s) && flags->isaccuracy)
	{
		ft_write(s, flags->accuracy, flags);
		ft_write(" ", flags->width - flags->accuracy, flags);
	}
	if (!flags->isaccuracy || flags->accuracy > ft_strlen(s))
	{
		ft_write(s, ft_strlen(s), flags);
		ft_write(" ", flags->width - ft_strlen(s), flags);
	}
}

static void		print_s_without(t_format *flags, char *s)
{
	int i;

	i = -1;
	if (flags->isaccuracy && flags->accuracy <= ft_strlen(s))
	{
		ft_write(" ", flags->width - flags->accuracy, flags);
		ft_write(s, flags->accuracy, flags);
	}
	if (!flags->isaccuracy || flags->accuracy > ft_strlen(s))
	{
		ft_write(" ", flags->width - ft_strlen(s), flags);
		ft_write(s, ft_strlen(s), flags);
	}
}

void			ft_print_s(t_format *flags, va_list argp)
{
	char	*s;

	s = va_arg(argp, char *);
	if (!s && flags->minus)
		print_s_minus(flags, "(null)");
	else if (!s && !flags->minus)
		print_s_without(flags, "(null)");
	else if (flags->minus)
		print_s_minus(flags, s);
	else if (!flags->minus)
		print_s_without(flags, s);
}
