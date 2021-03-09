/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvernon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 18:12:37 by rvernon           #+#    #+#             */
/*   Updated: 2020/11/01 20:52:26 by rvernon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t i;
	size_t len;

	i = 0;
	len = 0;
	if (!dst || !src)
		return (0);
	while (src[len] != '\0')
	{
		++len;
	}
	if (dstsize == 0)
		return (len);
	while (*src && (i < (dstsize - 1)))
	{
		*dst = *src;
		dst++;
		src++;
		++i;
	}
	*dst = '\0';
	return (len);
}
