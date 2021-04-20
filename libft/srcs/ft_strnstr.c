/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvernon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 12:23:48 by rvernon           #+#    #+#             */
/*   Updated: 2021/04/20 12:14:18 by mchaya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isequal(const char *s1, const char *s2)
{
	while (*s2)
	{
		if (*s2 != *s1)
			return (0);
		s1++;
		s2++;
	}
	return (1);
}

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = ft_strlen(little);
	if (big == little)
		return ((char *)big);
	if (ft_strlen(little) == 0 || !little)
		return ((char *)big);
	if (ft_strlen(big) < ft_strlen(little) || len == 0)
		return (NULL);
	while (i <= len - j && big[i] != '\0')
	{
		if (ft_isequal(big + i, little) == 0)
			i++;
		else
			return ((char *)(big + i));
	}
	return (NULL);
}
