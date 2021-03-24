/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvernon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 13:57:18 by rvernon           #+#    #+#             */
/*   Updated: 2021/03/24 16:46:08 by rvernon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <termios.h>
# include "libft.h"

typedef struct	s_all
{
	char 		**env;
}				t_all;

void	init_all(t_all *all);
void	error(int id);
void	start(t_all *all, char **env);
void	env_copy(t_all *all, char **from);
void	loop(t_all *all);
int		env(char **s);
void	echo(char **s);
# endif
