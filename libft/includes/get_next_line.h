/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvernon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 17:48:01 by rvernon           #+#    #+#             */
/*   Updated: 2021/04/01 20:04:31 by rvernon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFFER_SIZE 10
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include "libft.h"


int				get_next_line(int fd, char **line);
char			*ft_strchr(const char *s, int c);
char			*ft_join(char *s1, char *s2);
int				find_n(char *cache);
char			*ft_before_dup(int len, char *cache);
char			*before_n(char *cache);
char			*after_n(char *cache);

#endif
