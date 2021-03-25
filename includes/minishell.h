/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvernon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 13:57:18 by rvernon           #+#    #+#             */
/*   Updated: 2021/03/25 12:55:38 by rvernon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <termios.h>
# include <term.h>
# include <curses.h>
# include <sys/ioctl.h>
# include "libft.h"

typedef struct	s_all
{
	char 		**env;
	char		*start_line;
}				t_all;

void			init_all(t_all *all);
void			error(int id);
void			start(t_all *all, char **env);
void			env_copy(t_all *all, char **from);
int				env(char **s);
void			my_echo(char **s);
void			write_start_line(char *line);
void			pwd();
# endif
