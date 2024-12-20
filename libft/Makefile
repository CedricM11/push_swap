# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cedmarti <cedmarti@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/05 07:59:24 by cedmarti          #+#    #+#              #
#    Updated: 2024/12/13 15:58:02 by cedmarti         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIB =	ft_atoi.c ft_bzero.c ft_isalnum.c ft_isalpha.c		\
		ft_isascii.c ft_isdigit.c ft_isprint.c ft_memchr.c	\
		ft_memcmp.c ft_memmove.c ft_memset.c ft_strchr.c	\
		ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strncmp.c	\
		ft_strnstr.c ft_strrchr.c ft_tolower.c ft_toupper.c	\
		ft_calloc.c ft_strdup.c ft_memcpy.c					\

ADD =	ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c	\
		ft_itoa.c ft_strmapi.c ft_striteri.c ft_putchar_fd.c\
		ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c		\

BONUS = ft_lstnew_bonus.c ft_lstadd_front_bonus.c			\
		ft_lstsize_bonus.c ft_lstlast_bonus.c				\
		ft_lstadd_back_bonus.c ft_lstdelone_bonus.c			\
		ft_lstclear_bonus.c ft_lstiter_bonus.c				\
		ft_lstmap_bonus.c									\

SRCS = $(LIB) $(ADD)
SRCS_B = $(LIB) $(ADD) $(BONUS)

OBJS = $(SRCS:.c=.o)
OBJS_B = $(SRCS_B:.c=.o)

CC = gcc
CFLAGS = -Wall -Wextra -Werror -I ./

NAME = libft.a

all: $(NAME)

%.o: %.c
	@$(CC) $(CFLAGS) -o $@ -c $?

$(NAME): $(OBJS) $(OBJS_B)
	@ar rcs $(NAME) $(OBJS) $(OBJS_B)

clean:
	@rm -f $(OBJS) $(OBJS_B)

fclean: clean
	@rm -f $(NAME)

bonus: $(OBJS_B)
	@ar rcs $(NAME) $(OBJS_B)

re: fclean all
