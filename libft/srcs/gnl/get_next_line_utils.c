/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvernon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 17:52:18 by rvernon           #+#    #+#             */
/*   Updated: 2021/04/01 20:05:06 by rvernon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int			find_n(char *cache)
{
	if (!cache)
		return (0);
	while (*cache)
	{
		if (*cache == '\n')
			return (1);
		cache++;
	}
	return (0);
}

char		*ft_strchr(const char *s, int c)
{
	unsigned char *pc;

	pc = (unsigned char *)s;
	while (*pc != '\0' && *pc != (unsigned char)c)
	{
		pc++;
	}
	if (*pc == (unsigned char)c)
	{
		return ((char*)pc);
	}
	else
		return (NULL);
}



char		*ft_join(char *s1, char *s2)
{
	char	*news;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!s2)
		return (NULL);
	if (!(news = malloc(sizeof(char) *
		((!s1 ? 0 : ft_strlen(s1)) + ft_strlen(s2) + 1))))
		return (NULL);
	while (s1 && s1[i])
	{
		news[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		news[i + j] = s2[j];
		j++;
	}
	news[i + j] = '\0';
	free(s1);
	return (news);
}
