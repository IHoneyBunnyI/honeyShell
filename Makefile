# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rvernon <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/09 14:01:16 by rvernon           #+#    #+#              #
#    Updated: 2021/04/15 08:56:13 by rvernon          ###   ########.fr        #
#    Updated: 2021/03/24 14:07:33 by rvernon          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

CC = gcc

CFLAGS = -g -Wall -Wextra -Werror -Iincludes/ -I$(LIBFT_D)includes/

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
		unset.c\
		print_export.c\
		count_dot.c\
		cd.c\

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
