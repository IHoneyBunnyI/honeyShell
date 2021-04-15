/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvernon <rvernon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 14:41:20 by rvernon           #+#    #+#             */
/*   Updated: 2021/04/15 09:17:49 by rvernon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char *s1, char *s2)
{
	char	*news;
	int		i;
	int		j;

	j = 0;
	i = 0;
	if (!s2)
		return (NULL);
	news = malloc(sizeof(char) * (!s1 ? 0 : ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!news)
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
