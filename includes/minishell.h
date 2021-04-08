/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvernon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 13:57:18 by rvernon           #+#    #+#             */
/*   Updated: 2021/04/08 20:48:50 by rvernon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
#include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <termios.h>
# include <term.h>
# include <curses.h>
# include <sys/ioctl.h>
# include <sys/wait.h>
# include "libft.h"

typedef struct	s_all
{
	char 		**env;
	char		**av;
	char		*start_line;
	char		*command;
	char		**args;
}				t_all;

void			init_all(t_all *all);
void			error(int id);
void			start(t_all *all, char **av, char **env);
void			av_env_copy(t_all *all, char **av, char **env);
int				env(char **s);
void			my_echo(char **s);
void			write_start_line(char *line);
void			pwd();
void			parser(t_all *all, char *line);
void			export(t_all *all, char **env, char **args);
void			free_split(char **split);
void			unset(char **args);
void			print_export(char **env);
int				is_empty(char *s);
# endif
