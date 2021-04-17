/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvernon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 13:57:18 by rvernon           #+#    #+#             */
/*   Updated: 2021/04/17 15:28:05 by mchaya           ###   ########.fr       */
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
	int				is_oprt;
	char			*token;
	struct s_tokens	*next;
}				t_tokens;

char		*exit_env(char *cmnd_cpy, char *env_cpy, int k);
t_tokens	*flexer(char *cmnd, char **env);
int			exit_error(char *str);
void		check_operator(t_tokens *tmp, char **cmnd, int *is_set);
void		exp_env(char **cmnd, int *is_set, char **env, char **tk);
void		dbl_quot_bs(char **cmnd, char **tk);
void		operator_utils(t_tokens *tmp, char **cmnd, int *is_set);
int			check_sing_quot(char **cmnd, int *is_set, char **tk);
int			check_bs(char **cmnd, char **tk, int *is_set);
int			check_dbl_quot(char **cmnd, char **tk, int *is_set, char **env);
char		*check_env(char *cmnd, char **env);
char		*ft_angelina(char *p1, char *p2);
void		add_elem(t_tokens **tkn, t_tokens *tmp);
int			not_operator(char cmnd);
char		*make_cpy(char *src);
int			skip_env(char s);
void		make_lr(char *c, int *n, char *buf, int size);
int			ft_putstr(char *c);
int			ft_putint(int c);
void		make_bs(int *n);
void		init_term(struct termios *old);
#endif
