/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvernon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 14:41:08 by rvernon           #+#    #+#             */
/*   Updated: 2020/10/31 13:34:58 by rvernon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char *str;

	str = (unsigned char*)dst;
	if (!dst && !src)
	{
		return (dst);
	}
	while (n > 0)
	{
		*str = *((unsigned char*)src);
		str++;
		src++;
		n--;
	}
	return (dst);
}
