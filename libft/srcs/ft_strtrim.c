/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvernon <rvernon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 15:40:13 by rvernon           #+#    #+#             */
/*   Updated: 2021/02/20 19:17:49 by rvernon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ftstrchr(const char *s, int c)
{
	unsigned char *pc;

	pc = (unsigned char *)s;
	while (*pc != '\0' && *pc != (unsigned char)c)
	{
		pc++;
	}
	if (*pc == (unsigned char)c)
	{
		return (1);
	}
	else
		return (0);
}

char		*ft_strtrim(char const *s1, char const *set)
{
	char	*nstr;
	int		j;
	int		i;
	int		k;

	if (!s1 || !set)
		return (NULL);
	i = 0;
	j = ft_strlen(s1) - 1;
	k = 0;
	while (s1[i] && ftstrchr(set, s1[i]) == 1)
		i++;
	if (j == -1 || i == ((int)ft_strlen(s1)))
		return (ft_strdup(""));
	while (ftstrchr(set, s1[j]) == 1)
		j--;
	if (!(nstr = malloc(sizeof(char) * (j - i + 2))))
		return (NULL);
	while (i <= j)
	{
		nstr[k++] = s1[i];
		i++;
	}
	nstr[k] = '\0';
	return (nstr);
}
