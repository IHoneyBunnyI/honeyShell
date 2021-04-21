/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arrow.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchaya <mchaya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 14:33:09 by mchaya            #+#    #+#             */
/*   Updated: 2021/04/21 16:34:23 by mchaya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_tokens	*next_command(char *buf, t_ar *ar, char **env)
{
	t_tokens	*tkn;

	buf[ar->size * 4000 + ar->n] = 0;
	tkn = flexer(buf + (ar->size * 4000), env);
	if (buf[ar->size * 4000])
	{
		if (ar->size < 1000)
			(ar->size)++;
		ar->i = ar->size;
		buf[ar->size * 4000] = 0;
	}
	ar->n = 0;
	return (tkn);
}

void	start(t_ar *ar, char *buf, char **envp)
{
	char			c[5];
	t_tokens		*tkn;

	while (ft_strcmp(c, "\4"))
	{
		tputs(save_cursor, 1, ft_putint);
		ft_putstr("🚀 $ ");
		while (1)
		{
			ar->r = read(0, c, 10);
			c[ar->r] = 0;
			if (check_key(c))
				make_key(c, ar, &buf);
			else if (!ft_strcmp(c, "\4") && !ar->n)
				break ;
			else
				write_buf(buf, ar, c);
			if (!ft_strcmp(c, "\n"))
			{
				tkn = next_command(buf, ar, envp);
				break ;
			}
		}
	}
}

int	main(int argc, char **argv, char **envp)
{
	struct termios	old;
	t_ar			ar;
	char			*buf;

	init_all(&ar, &old, &buf);
	start(&ar, buf, envp);
	return (exit_term(&old, buf));
}
