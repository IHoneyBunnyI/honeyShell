/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvernon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 12:55:41 by rvernon           #+#    #+#             */
/*   Updated: 2021/02/14 13:30:20 by rvernon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

char		*ft_get_type(char *format, t_format *flags, va_list argp)
{
	flags->type = *format;
	format++;
	if (flags->type == 'c')
		ft_print_c(flags, argp);
	else if (flags->type == 's')
		ft_print_s(flags, argp);
	else if (flags->type == 'p')
		ft_print_p(flags, argp);
	else if (flags->type == 'd')
		ft_print_d(flags, argp);
	else if (flags->type == 'i')
		ft_print_d(flags, argp);
	else if (flags->type == 'u')
		ft_print_u(flags, argp);
	else if (flags->type == 'x')
		ft_print_x(flags, argp);
	else if (flags->type == 'X')
		ft_print_bx(flags, argp);
	else if (flags->type == '%')
		ft_print_percent(flags);
	return (format);
}

int			ft_printf(const char *format, ...)
{
	va_list		argp;
	t_format	flags;

	if (!format)
		return (-1);
	va_start(argp, format);
	flags.length = 0;
	while (*format)
	{
		format = ft_print_all((char *)format, &flags);
		if (*format == '%')
		{
			flags = ft_initial_flags(&flags);
			format = ft_get_flags((char*)format, &flags);
			format = ft_get_width((char *)format, &flags, argp);
			format = ft_get_accuracy((char *)format, &flags, argp);
			format = ft_get_type((char *)format, &flags, argp);
		}
	}
	va_end(argp);
	return (flags.length);
}
