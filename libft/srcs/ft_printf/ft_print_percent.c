/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_percent.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvernon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/11 19:35:20 by rvernon           #+#    #+#             */
/*   Updated: 2020/12/11 21:27:21 by rvernon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

void		ft_print_percent(t_format *flags)
{
	if (flags->minus)
	{
		ft_write("%", 1, flags);
		ft_write(" ", flags->width - 1, flags);
	}
	else if (flags->null)
	{
		ft_write("0", flags->width - 1, flags);
		ft_write("%", 1, flags);
	}
	else if (!flags->null && !flags->minus)
	{
		ft_write(" ", flags->width - 1, flags);
		ft_write("%", 1, flags);
	}
}
