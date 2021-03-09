/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_d2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvernon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/13 20:20:10 by rvernon           #+#    #+#             */
/*   Updated: 2020/12/13 20:20:51 by rvernon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

void		print_d_minus_min(t_format *flags, char *s)
{
	if (flags->isaccuracy && flags->accuracy > ft_strlen(s))
	{
		ft_write("-", 1, flags);
		ft_write("0", flags->accuracy - ft_strlen(s), flags);
		ft_write(s, ft_strlen(s), flags);
		ft_write(" ", flags->width - flags->accuracy - 1, flags);
	}
	if (!flags->isaccuracy || (flags->isaccuracy &&
				flags->accuracy <= ft_strlen(s)))
	{
		ft_write("-", 1, flags);
		ft_write(s, ft_strlen(s), flags);
		ft_write(" ", flags->width - ft_strlen(s) - 1, flags);
	}
}

void		print_d_minus(t_format *flags, char *s)
{
	if (flags->isaccuracy && flags->accuracy > ft_strlen(s))
	{
		ft_write("0", flags->accuracy - ft_strlen(s), flags);
		ft_write(s, ft_strlen(s), flags);
		ft_write(" ", flags->width - flags->accuracy, flags);
	}
	if (!flags->accuracy || (flags->isaccuracy &&
				flags->accuracy <= ft_strlen(s)))
	{
		ft_write(s, ft_strlen(s), flags);
		ft_write(" ", flags->width - ft_strlen(s), flags);
	}
}

void		print_d_null(t_format *flags, char *s)
{
	if (flags->isaccuracy && flags->accuracy > ft_strlen(s))
	{
		ft_write(" ", flags->width - flags->accuracy, flags);
		ft_write("0", flags->accuracy - ft_strlen(s), flags);
		ft_write(s, ft_strlen(s), flags);
	}
	if (flags->isaccuracy && flags->accuracy <= ft_strlen(s))
	{
		ft_write(" ", flags->width - ft_strlen(s), flags);
		ft_write(s, ft_strlen(s), flags);
	}
	if (!flags->isaccuracy)
	{
		ft_write("0", flags->width - ft_strlen(s), flags);
		ft_write(s, ft_strlen(s), flags);
	}
}
