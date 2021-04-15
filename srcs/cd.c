/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvernon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 08:54:01 by rvernon           #+#    #+#             */
/*   Updated: 2021/04/15 09:43:24 by rvernon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	update_oldpwd(t_all *all)
{
	int	i;
	int	i_pwd;
	int	i_oldpwd; 
	char *pwd;

	i = -1;
	i_pwd = find_name(all, "PWD") - 1;
	i_oldpwd = find_name(all, "OLDPWD") - 1;
	free(all->env[i_oldpwd]);
	pwd = all->env[i_pwd];
	while (all->env[i_pwd][++i] != '=')
		pwd++;
	all->env[i_oldpwd] = ft_strdup("OLDPWD=");
	all->env[i_oldpwd] = ft_strjoin(all->env[i_oldpwd], ++pwd);
}

void	update_pwd(t_all *all)
{
	char *pwd;
	int	i_pwd;

	i_pwd = find_name(all, "PWD") - 1;
	free(all->env[i_pwd]);
	all->env[i_pwd] = ft_strdup("PWD=");
	pwd = getcwd(0, 0);
	all->env[i_pwd] = ft_strjoin(all->env[i_pwd], pwd);
	free(pwd);
}

void	cd_error(char *line)
{
	ft_putstr_fd("🚀: cd: ", 2);
	ft_putstr_fd(line, 2);
	ft_putstr_fd(": ", 2);
	ft_putendl_fd(strerror(errno), 2);
}

void	cd(t_all *all, char **args)
{
	if (chdir(args[1]) != -1)
	{
		update_oldpwd(all);
		update_pwd(all);
	}
	else
	{
		cd_error(args[1]);
	}
}
