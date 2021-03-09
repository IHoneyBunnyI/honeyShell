/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvernon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 14:58:34 by rvernon           #+#    #+#             */
/*   Updated: 2020/11/02 15:22:39 by rvernon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		numlen(int n)
{
	int len;

	len = 0;
	if (n == 0)
		return (1);
	if (n < 0)
		len++;
	while (n != 0)
	{
		len++;
		n = n / 10;
	}
	return (len);
}

char			*ft_itoa(int n)
{
	char	*nbr;
	int		count;
	int		sign;

	count = numlen(n);
	sign = 1;
	if (n < 0)
		sign = -1;
	if (!(nbr = malloc(sizeof(char) * (count + 1))))
		return (NULL);
	nbr[count] = '\0';
	count--;
	{
		while (count >= (sign == -1 ? 1 : 0))
		{
			if (sign < 0)
				nbr[0] = '-';
			nbr[count] = ((n % 10) * sign) + '0';
			n = n / 10;
			count--;
		}
	}
	return (nbr);
}
