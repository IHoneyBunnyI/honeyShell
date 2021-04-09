/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvernon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 13:57:18 by rvernon           #+#    #+#             */
/*   Updated: 2021/04/09 17:26:01 by mchaya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <termios.h>
# include <stdio.h>
# include <unistd.h>
# include <string.h>
# include <term.h>
# include <curses.h>
# include <sys/ioctl.h>
# include <stdlib.h>
# include "libft.h"

typedef struct s_tokens
{
	struct tokens	prev;
	struct tokens	next;
	char			*token;
}				t_tokens;

typedef struct s_all
{
	char		**env;
}				t_all;

void	make_lr(char *c, int *n, char *buf, int size);
int		ft_putstr(char *c);
int		ft_putint(int c);
void	make_bs(int *n);
void	init_term(struct termios *old);
void	init_all(t_all *all);
void	error(int id);
void	start(t_all *all, char **env);
void	env_copy(t_all *all, char **from);
void	loop(t_all *all);
int		env(char **s);
#endif
