/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvernon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 14:37:35 by rvernon           #+#    #+#             */
/*   Updated: 2021/04/14 16:43:29 by rvernon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H
# include <stdarg.h>
# include <stdio.h>
# include "libft.h"

typedef struct s_format
{
	int		minus;
	int		null;
	int		width;
	int		accuracy;
	char	type;
	int		length;
	int		spaces;
	int		isaccuracy;
}				t_format;

int				ft_printf(const char *format, ...);
void			ft_write(char *c, int len, t_format *flags);
char			*ft_print_all(char *format, t_format *str);
t_format		ft_initial_flags(t_format *flags);
char			*ft_get_flags(char *format, t_format *flags);
char			*ft_get_width(char *format, t_format *flags, va_list argp);
char			*ft_get_accuracy(char *format, t_format *flags, va_list argp);
void			ft_print_c(t_format *flags, va_list argp);
void			ft_print_s(t_format *flags, va_list argp);
void			ft_print_p(t_format *flags, va_list argp);
void			ft_print_d(t_format *flags, va_list argp);
void			ft_print_u(t_format *flags, va_list argp);
void			ft_print_x(t_format *flags, va_list argp);
void			ft_print_bx(t_format *flags, va_list argp);
int				ft_nblen(unsigned int n);
void			ft_print_percent(t_format *flags);
void			print_d_null_null(t_format *flags);
void			print_d_without_min(t_format *flags, char *s);
void			print_d_without(t_format *flags, char *s);
void			print_d_null_min(t_format *flags, char *s);
void			print_d_null(t_format *flags, char *s);
void			print_d_minus(t_format *flags, char *s);
void			print_d_minus_min(t_format *flags, char *s);

#endif
