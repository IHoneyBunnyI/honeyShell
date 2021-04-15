/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvernon <rvernon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 15:13:38 by rvernon           #+#    #+#             */
/*   Updated: 2021/04/15 07:24:37 by rvernon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t			i;
	unsigned char	*a;
	unsigned char	*str;

	i = 0;
	a = (unsigned char *)dst;
	str = (unsigned char *)src;
	if (!dst && !src)
		return (dst);
	while (i < n)
	{
		if (*str == (unsigned char)c)
		{
			*a = *((unsigned char *)str);
			return ((void *)dst + i + 1);
		}
		else
		{
			*a = *((unsigned char *)str);
			a++;
			str++;
			i++;
		}
	}
	return (NULL);
}
