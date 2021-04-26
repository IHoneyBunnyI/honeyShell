#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <termios.h>
# include <term.h>
# include <curses.h>
# include <sys/ioctl.h>
# include <sys/stat.h>
# include <sys/wait.h>
# include "libft.h"
# include <sys/errno.h>
# include <fcntl.h>


typedef struct s_cmd
{
	char	**files;
	char	*cmd;
	char	**args;
	int		pipe;
	int		fd;
}	t_cmd;

typedef struct s_all
{
	char	**env;
	char	**av;
	char	*start_line;
	char	*command;
	char	**args;
	char	**all_args;
	char	*files;
	int		dots;
	int		exit_status;
	int			fds[2];
}	t_all;

typedef struct s_tokens
{
	int				is_oprt;
	char			*token;
	struct s_tokens	*next;
}				t_tokens;

typedef struct s_ar
{
	int			size;
	int			i;
	int			n;
	int			r;
}				t_ar;

void		error(int id, struct termios *old, char *buf);
void		av_env_copy(t_all *all, char **av, char **env);
void		my_echo(char **s, int fd);
void		write_start_line(char *line);
void		pwd(int fd);
void		parser(t_all *all, char *line);
void		free_split(char **split);
void		my_unset(t_all *all, char **args);
int			is_empty(char *s);
void		count_dot(t_all *all, char *line);
void		cd(t_all *all, char **args);
int			find_name(t_all *all, char *arg);
void		ft_exit(t_all *all, char **args);
int			is_echo(char *l);
void		init_const(t_all *all);
void		my_execve(t_all *all, char **args, int fd);
void		export(t_all *all, char **args, int fd);
void		print_export(char **env, int fd);
int			env(char **s, int fd);
void		init_ar(t_ar *ar);
void		init_all(t_ar *ar, struct termios *old, char **buf, t_all *all);
void		write_buf(char *buf, t_ar *ar, char *c);
int			make_keydown(char *buf, int size, int i);
int			make_keyup(char *sbuf, char *ibuf);
int			check_key(char *c);
int			exit_term(struct termios *old, char *buf);
void		make_key(char *c, t_ar *ar, char **buf);
char		*exit_env(char *cmnd_cpy, char *env_cpy, int k);
char		**convert_tkn(t_tokens *tkn);
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
void		start(t_ar *ar, char *buf, t_all *all, char **env);
void		work_command(t_all *all, t_tokens *tkn);
t_tokens	*next_command(char *buf, t_ar *ar, char **env);
void		init_cmd(t_cmd *cmd);
int			parse_redirect(t_all *all, char **args, t_cmd *cmd);
void		get_args(char **args, t_cmd *cmd);
#endif
