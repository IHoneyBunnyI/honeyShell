# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rvernon <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/09 14:01:16 by rvernon           #+#    #+#              #
#    Updated: 2021/03/23 20:03:07 by rvernon          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

CC = gcc

CFLAGS = -Wall -Wextra -Werror -Iincludes/ -I$(LIBFT_D)includes/

FILES = main.c\
		init_all.c\
		error.c\

LIBFT_D = libft/

LIBFT = $(LIBFT_D)libft.a

SRCS = $(addprefix srcs/, $(FILES))

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(LIBFT) $(OBJS) 
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) -Llibft/ -lft

$(LIBFT): $(LIBFT_D)
	@$(MAKE) -C $(LIBFT_D)

clean:
	rm -rf $(OBJS)
	@$(MAKE) -C $(LIBFT_D) clean
	$(RM) $(LIBFT)

fclean: clean
	rm -rf $(NAME)

re: fclean all
