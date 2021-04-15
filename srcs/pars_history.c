/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_history.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchaya <mchaya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 16:30:18 by mchaya            #+#    #+#             */
/*   Updated: 2021/04/13 15:33:24 by mchaya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"
#include "../libft/includes/libft.h"

char	*ft_angelina(char *p1, char *p2)
{
	char	*res;
	int		i;

	i = 0;
	res = malloc(p2 - p1 - 1);
	p1++;
	while (p1 != p2)
	{
		res[i] = *p1;
		i++;
		p1++;
	}
	res[i] = '\0';
	return (res);
}

void	add_elem(t_tokens **tkn, t_tokens *tmp)
{
	t_tokens *plst;

	if (!tkn)
		return ;
	plst = *tkn;
	if (!*tkn)
	{
		*tkn = tmp;
		return ;
	}
	if (!tmp)
		return ;
	while (plst->next)
		plst = plst->next;
	plst->next = tmp;
}

int	not_operator(char cmnd)
{
	if (cmnd == ';' || cmnd == '|' || cmnd == '<' || cmnd == '>')
		return (0);
	return (1);
}

char	*make_cpy(char *src)
{
	char	*res;
	int		len;
	int		i;

	i = 0;
	len = ft_strlen(src);
	if (!(res = malloc(len + 1)))
		return (0);
	while (src[i])
	{
		res[i] = src[i];
		i++;
	}
	res[i] = '\0';
	return (res);
}

int	skip_env(char s)
{
	if (ft_isalnum(s) || s == '_')
		return (1);
	return (0);
}

char	*check_env(char *cmnd, char **env)
{
	char	*cmnd_cpy;
	char	*env_cpy;
	char	*res;
	int		i;
	int		k;

	i = 0;
	cmnd_cpy = make_cpy(cmnd);
	while (skip_env(cmnd_cpy[i]))
		i++;
	cmnd_cpy[i] = '\0';
	i = 0;
	while (env[i])
	{
		k = 0;
		env_cpy = make_cpy(env[i]);
		while (env_cpy[k] != '=')
			k++;
		env_cpy[k] = '\0';
		if (!ft_strcmp(env_cpy, cmnd_cpy))
		{
			free(cmnd_cpy);
			res = make_cpy(env_cpy + (++k));
			free(env_cpy);
			return (res);
		}
		free(env_cpy);
		i++;
	}
	return ("");
}

void	exp_env(char **cmnd, int *is_set, char **env, char **tk)
{
	char *res;

	(*cmnd)++;
	if (ft_isdigit(**cmnd))
		(*cmnd)++;
	else if (!ft_isalpha(**cmnd) || **cmnd == '_')
	{
		*tk = ft_strjoin(*tk, "$");
		*is_set = 1;
	}
	else
	{
		res = check_env(*cmnd, env);
		*tk = ft_strjoin(*tk, res);
		while (skip_env(**cmnd))
			(*cmnd)++;
		if (ft_strcmp(res, ""))
			*is_set = 1;
	}
}

t_tokens	*flexer(char *cmnd, char **env)
{
	t_tokens	*tkn;
	t_tokens	*tmp;
	char		*tk;
	char		*str;
	int			is_set;

	tkn = NULL;
	while (*cmnd)
	{
		is_set = 0;
		tmp = malloc(sizeof(t_tokens));
		while (*cmnd == ' ' && *cmnd)
			cmnd++;
		if (*cmnd == '\0')
			break;
		if (*cmnd == ';' || *cmnd == '|' || *cmnd == '<')
		{
			tmp->is_oprt = 1;
			tmp->token = malloc(2);
			tmp->token[0] = *cmnd;
			tmp->token[1] = '\0';
			tmp->next = NULL;
			cmnd++;
			is_set = 1;
		}
		else if (*cmnd == '>')
		{
			tmp->is_oprt = 1;
			if (*(cmnd + 1) == '>')
			{
				tmp->token = malloc(3);
				tmp->token[1] = *cmnd;
				tmp->token[2] = '\0';
				cmnd++;
			}
			else
			{
				tmp->token = malloc(2);
				tmp->token[1] = '\0';
			}
			tmp->token[0] = '>';
			tmp->next = NULL;
			cmnd++;
			is_set = 1;
		}
		else
		{
			tk = malloc(1);
			tk[0] = '\0';
			while (not_operator(*cmnd) && *cmnd != ' ' && *cmnd != '\0')
			{
				if (*cmnd == '\'')
				{
					char *p1;
					char *p2;

					p1 = cmnd;
					p2 = cmnd;
					p2++;
					while (*p2 && *p2 != '\'')
						p2++;
					if (!(*p2))
					{
						printf("Error: unclosed quotation\n");
						exit(0);
					}
					str = ft_angelina(p1, p2);
					tk = ft_strjoin(tk, str);
					cmnd = p2 + 1;
					is_set = 1;
				}
				else if (*cmnd == '\\')
				{
					char t[2];
					t[1] = 0;
					cmnd++;
					if (!(*cmnd))
					{
						printf("Error: escaped newline\n");
						exit(1);
					}
					t[0] = *cmnd;
					tk = ft_strjoin(tk, t);
					if (*cmnd)
						cmnd++;
					is_set = 1;
				}
				else if (*cmnd == '$')
					exp_env(&cmnd, &is_set, env, &tk);
				else if (*cmnd == '\"')
				{
					char	t[3];
					is_set = 1;
					cmnd++;
					while (*cmnd != '\"' && *cmnd != '\0')
					{
						if (*cmnd == '$')
							exp_env(&cmnd, &is_set, env, &tk);
						else if (*cmnd == '\\')
						{
							cmnd++;
							if (*cmnd == '$' || *cmnd == '`' || *cmnd == '\\'
							|| *cmnd == '\"')
							{
								t[0] = *cmnd;
								t[1] = '\0';
							}
							else
							{
								t[0] = '\\';
								t[1] = *cmnd;
								t[2] = '\0';
							}
							tk = ft_strjoin(tk, t);
							cmnd++;
						}
						else
						{
							t[0] = *cmnd;
							t[1] = '\0';
							tk = ft_strjoin(tk, t);
							cmnd++;
						}
					}
					if (!(*cmnd))
					{
						printf("Error: unclosed quotation\n");
						exit(1);
					}
					cmnd++;
				}
				else
				{
					char t[2];
					t[1] = 0;
					t[0] = *cmnd;
					tk = ft_strjoin(tk, t);
					if (*cmnd)
						cmnd++;
					is_set = 1;
				}
			}
			tmp->token = tk;
			tmp->next = NULL;
			tmp->is_oprt = 0;
		}
		if (is_set)
			add_elem(&tkn, tmp);
	}
	return (tkn);
}

int main(int argc, char **argv, char **envp)
{
	char *str = "echo $dlkld \\";
	t_tokens	*tkn;

	tkn = flexer(str, envp);
	while (tkn)
	{
		printf("tk = %s, oprt = %d\n", tkn->token, tkn->is_oprt);
		tkn = tkn->next;
	}
	return (0);
}