/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvernon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 14:07:24 by rvernon           #+#    #+#             */
/*   Updated: 2021/04/01 18:24:02 by rvernon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

	//ППППППП И   ИИ Ш   Ш   Ш И   ИИ     ППППППП     А     РРРРРР    СССС   ЕЕЕЕЕЕЕ РРРРРР
	//П     П И  И И Ш   Ш   Ш И  И И     П     П    А А    Р     Р  С    С  Е       Р     Р
	//П     П И И  И Ш   Ш   Ш И И  И     П     П   А   А   РРРРРР   С       ЕЕЕЕЕЕЕ РРРРРР
	//П     П ИИ   И Ш   Ш   Ш ИИ   И     П     П  ААААААА  Р        С    С  Е       Р
	//П     П И    И ШШШШШШШШШ И    И     П     П А       А Р         СССС   ЕЕЕЕЕЕЕ Р

int		find_len_command(char *line)
{
	int i;
	int len;

	i = 0;
	len = 0;
	while (line[i] != ' ' && line[i] != '\0')
	{
		if (line[i] != '\'' && line[i] != '"')
			len++;
		i++;
	}
	return (len);
}

void	get_line_command(t_all *all, char *line, int len)
{
	int i;

	i = 0;
	all->command = malloc(sizeof(char) * (len + 1));
	while (line[i])
	{
		if (line[i] == '"')
			i++;
		else
		{
			all->command[i] = line[i];
			i++;
		}
	}
	all->command[i] = 0;
}

void	get_command(t_all *all, char *line)
{
	int len;

	(void)all;
	len = find_len_command(line);
	get_line_command(all, line, len);
	/*printf("%d\n", len);*/
	/*printf("%s", all->command);*/
}
void	parser(t_all *all, char *line)
{
	get_command(all, line);
}
