/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvernon <rvernon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 22:36:46 by rvernon           #+#    #+#             */
/*   Updated: 2020/11/01 20:51:22 by rvernon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char			*pc;
	unsigned int	i;

	i = 0;
	pc = (char *)s;
	while (s[i] != '\0')
		i++;
	i++;
	while (i--)
	{
		if (s[i] == (char)c)
			return (pc + i);
	}
	return (NULL);
}
