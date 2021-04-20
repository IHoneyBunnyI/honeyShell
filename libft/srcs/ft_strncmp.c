/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvernon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 14:45:47 by rvernon           #+#    #+#             */
/*   Updated: 2021/04/20 12:14:18 by mchaya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned int	j;

	j = 0;
	while (j < n && s1[j] != '\0' && s2[j] != '\0')
	{
		if (s1[j] != s2[j])
		{
			return ((unsigned char)s1[j] - (unsigned char)s2[j]);
		}
		j++;
	}
	if (j < n && (s1[j] || s2[j]))
		return ((unsigned char)s1[j] - (unsigned char)s2[j]);
	return (0);
}
