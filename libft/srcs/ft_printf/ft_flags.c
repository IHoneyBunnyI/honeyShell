/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvernon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/06 11:56:23 by rvernon           #+#    #+#             */
/*   Updated: 2021/02/14 14:49:13 by rvernon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

char		*ft_get_flags(char *format, t_format *flags)
{
	format++;
	while (*format == '-' || *format == '0' || *format == ' ')
	{
		if (*format == '-')
			flags->minus = 1;
		if (*format == '0')
			flags->null = 1;
		if (*format == ' ')
			ft_write(" ", 1, flags);
		format++;
	}
	return (format);
}

char		*ft_get_width(char *format, t_format *flags, va_list argp)
{
	int width;

	width = 0;
	if (*format != '.' || ft_isalpha(*format))
		flags->width = ft_atoi(format);
	if (*format == '*')
	{
		width = va_arg(argp, int);
		if (width < 0)
		{
			flags->minus = 1;
			flags->width = -width;
		}
		else
			flags->width = width;
	}
	while (ft_isdigit(*format) || *format == '*')
		format++;
	return (format);
}

char		*ft_get_accuracy(char *format, t_format *flags, va_list argp)
{
	int	accuracy;

	accuracy = 0;
	if (*format == '.')
	{
		format++;
		flags->isaccuracy = 1;
	}
	if (!ft_isalpha(*format) || ft_isdigit(*format))
		flags->accuracy = ft_atoi(format);
	if (*format == '*')
	{
		accuracy = va_arg(argp, int);
		if (accuracy >= 0)
			flags->accuracy = accuracy;
		else
			flags->isaccuracy = 0;
	}
	while (ft_isdigit(*format) || *format == '*')
		format++;
	return (format);
}
