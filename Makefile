NAME = honeyshell

CC = gcc

CFLAGS = -Wall -Wextra -Werror -Iincludes/ -I$(LIBFT_D)includes/

FILES = main.c\
		init_all.c\
		error.c\
		start.c\
		env.c\
		echo.c\
		util.c\
		pwd.c\
		parser.c\
		arrow.c\
		av_env_copy.c\
		export.c\
		export_util.c\
		export_util2.c\
		unset.c\
		print_export.c\
		count_dot.c\
		cd.c\
		ft_exit.c\
		my_execve.c\
		my_execve_util.c\
		arrow_utils.c\
		check_token.c\
		check_utils.c\
		pars_history.c\
		pars_utils.c\
		term_utils.c\
		term_utils2.c\
		token_work.c\
		main_utils.c\
		work_command.c\
		work_command_util.c\
		work_command_util_2.c\
		parse_redirect.c\
		parse_redirect_util.c\
		get_args.c\
		signal.c\
		parse_pipes.c\
		parse_dollars.c\
		check_find_dots.c\


LIBFT_D = libft/

LIBFT = $(LIBFT_D)libft.a

SRCS = $(addprefix srcs/, $(FILES))

FILES_O = $(addprefix objs/, $(FILES))

OBJS = $(FILES_O:.c=.o)

objs/%.o: srcs/%.c
	$(CC) $(CFLAGS) -c $<  -o $@

all: $(NAME)

$(NAME): $(LIBFT) $(OBJS) 
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) -Llibft/ -lft -ltermcap

$(LIBFT): $(LIBFT_D)
	@$(MAKE) -C $(LIBFT_D)

clean:
	rm -rf $(OBJS)
	@$(MAKE) -C $(LIBFT_D) clean
	$(RM) $(LIBFT)

fclean: clean
	rm -rf $(NAME)

re: fclean all
