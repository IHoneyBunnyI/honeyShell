/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvernon <rvernon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 14:41:20 by rvernon           #+#    #+#             */
/*   Updated: 2021/04/15 13:00:43 by rvernon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char *s1, char *s2)
{
	char	*news;
	int		i;
	int		j;

	j = -1;
	if (!s2)
		return (NULL);
	if (!s1)
		i = 0;
	else
		i = ft_strlen(s1) + ft_strlen(s2) + 1;
	news = malloc(sizeof(char) * i);
	if (!news)
		return (NULL);
	i = -1;
	while (s1 && s1[++i])
		news[i] = s1[i];
	while (s2[++j])
		news[i + j] = s2[j];
	news[i + j] = '\0';
	free(s1);
	return (news);
}
