# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rvernon <rvernon@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/10/30 13:32:12 by rvernon           #+#    #+#              #
#    Updated: 2021/03/09 14:29:50 by rvernon          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
FILE = ft_memset.c\
	   ft_bzero.c\
	   ft_memcpy.c\
	   ft_memccpy.c\
	   ft_memmove.c\
	   ft_memchr.c\
	   ft_memcmp.c\
	   ft_strlen.c\
	   ft_strlcpy.c\
	   ft_strlcat.c\
	   ft_strchr.c\
	   ft_strrchr.c\
	   ft_isalpha.c\
	   ft_isdigit.c\
	   ft_isalnum.c\
	   ft_isascii.c\
	   ft_isprint.c\
	   ft_toupper.c\
	   ft_tolower.c\
	   ft_strnstr.c\
	   ft_strncmp.c\
	   ft_strcmp.c\
	   ft_atoi.c\
	   ft_strdup.c\
	   ft_calloc.c\
			ft_substr.c\
			ft_strjoin.c\
			ft_putchar_fd.c\
		 	ft_putstr_fd.c\
			ft_putendl_fd.c\
			ft_putnbr_fd.c\
			ft_itoa.c\
			ft_itoa_base.c\
			ft_strmapi.c\
			ft_strtrim.c\
			ft_split.c\
			   ft_lstnew.c\
			   ft_lstadd_front.c\
			   ft_lstsize.c\
			   ft_lstlast.c\
			   ft_lstadd_back.c\
			   ft_lstdelone.c\
			   ft_lstclear.c\
			   ft_lstiter.c\
			   ft_lstmap.c\
			gnl/get_next_line.c\
			gnl/get_next_line_utils.c\
				ft_printf/ft_flags.c\
				ft_printf/ft_utils.c\
				ft_printf/ft_printf.c\
				ft_printf/ft_print_c.c\
				ft_printf/ft_print_d.c\
				ft_printf/ft_print_p.c\
				ft_printf/ft_print_s.c\
				ft_printf/ft_print_u.c\
				ft_printf/ft_print_x.c\
				ft_printf/ft_print_bx.c\
				ft_printf/ft_print_d2.c\
				ft_printf/ft_print_percent.c\

SRCS = $(addprefix srcs/, $(FILE))
HEADER = includes/ 
OBJS = ${SRCS:.c=.o}
CC = gcc
CFLAGS = -Wall -Wextra -Werror -I ${HEADER}

all:    ${NAME}

$(NAME): ${OBJS}
	@ar rc ${NAME} ${OBJS}

clean: 
	rm -rf ${OBJS} ${BONUSOBJ}
fclean: clean
	rm -rf ${NAME}
bonus: ${BONUSOBJ}
	ar rc ${NAME} ${BONUSOBJ}
re: fclean all

.PHONY: all clean fclean re
