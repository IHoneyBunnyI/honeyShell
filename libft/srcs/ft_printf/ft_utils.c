/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvernon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 18:51:51 by rvernon           #+#    #+#             */
/*   Updated: 2021/02/14 13:30:29 by rvernon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

t_format			ft_initial_flags(t_format *flags)
{
	flags->minus = 0;
	flags->null = 0;
	flags->width = 0;
	flags->accuracy = 0;
	flags->type = '0';
	flags->isaccuracy = 0;
	return (*flags);
}

char				*ft_print_all(char *format, t_format *flags)
{
	int i;

	i = 0;
	if (format && *format != '%')
	{
		write(1, format, 1);
		flags->length += 1;
		format++;
	}
	return (format);
}

void				ft_write(char *c, int len, t_format *flags)
{
	int i;

	i = -1;
	if (len <= 0)
		;
	else if (ft_strlen(c) < len)
	{
		while (++i < len)
		{
			write(1, c, 1);
			flags->length += 1;
		}
	}
	else
	{
		write(1, c, len);
		flags->length += len;
	}
}
