/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvernon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 17:47:26 by rvernon           #+#    #+#             */
/*   Updated: 2021/04/01 20:05:03 by rvernon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char			*ft_before_dup(int len, char *cache)
{
	char	*res;
	int		i;

	i = 0;
	if (!(res = malloc(len + 1)))
		return (0);
	while (i < len)
	{
		res[i] = cache[i];
		i++;
	}
	res[i] = '\0';
	return (res);
}

char			*before_n(char *cache)
{
	int		i;
	char	*res;

	i = 0;
	while (cache && cache[i] && cache[i] != '\n')
		i++;
	res = ft_before_dup(i, cache);
	return (res);
}

char			*after_n(char *cache)
{
	int		i;
	char	*res;
	char	*n;

	i = 0;
	while (cache && cache[i] && cache[i] != '\n')
		i++;
	if (!cache || !cache[i])
	{
		free(cache);
		return (0);
	}
	n = ft_strchr(cache, '\n');
	n += 1;
	res = ft_strdup(n);
	free(cache);
	return (res);
}

int				get_next_line(int fd, char **line)
{
	static char	*cache;
	char		*buffer;
	int			readed;

	readed = 1;
	if (fd < 0 || !line || BUFFER_SIZE <= 0)
		return (-1);
	if (!(buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1))))
		return (-1);
	while (!find_n(cache) && (readed = read(fd, buffer, BUFFER_SIZE)))
	{
		if (readed < 0)
		{
			free(buffer);
			free(cache);
			return (-1);
		}
		buffer[readed] = '\0';
		cache = ft_join(cache, buffer);
	}
	free(buffer);
	*line = before_n(cache);
	cache = after_n(cache);
	return (readed == 0 ? 0 : 1);
}
