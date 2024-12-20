# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cedmarti <cedmarti@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/11 08:38:59 by cedmarti          #+#    #+#              #
#    Updated: 2024/11/28 10:12:20 by cedmarti         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = 	ft_num_len.c ft_print_char.c ft_print_hex.c \
		ft_print_num.c ft_print_ptr.c ft_printf.c

OBJS = $(SRCS:.c=.o)

CC = gcc
CFLAGS = -Wall -Wextra -Werror

NAME = libftprintf.a

all: $(NAME)

%.o: %.c
	@$(CC) $(CFLAGS) -o $@ -c $?

$(NAME): $(OBJS)
	@ar rcs $(NAME) $(OBJS)

clean:
	@rm -f $(OBJS)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
