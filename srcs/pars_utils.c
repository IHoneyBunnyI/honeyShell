#include "minishell.h"

char	*ft_angelina(char *p1, char *p2)
{
	char	*res;
	int		i;

	i = 0;
	res = malloc(p2 - p1);
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
	t_tokens	*plst;

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

int	skip_env(char s)
{
	if (ft_isalnum(s) || s == '_')
		return (1);
	return (0);
}

void	else_else(char **ret, int *j, char *args, t_all *all)
{
	char	*buf;

	buf = check_env(&args[*j], all->env);
	if (buf)
	{
		*ret = ft_strjoin(*ret, buf);
		free(buf);
	}
	while (skip_env(args[*j]))
		(*j)++;
}
