# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cedmarti <cedmarti@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/13 10:05:31 by cedmarti          #+#    #+#              #
#    Updated: 2024/12/26 15:04:03 by cedmarti         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS =	srcs/main.c srcs/create_list.c srcs/check_error.c \
		srcs/swap.c srcs/push.c srcs/rotate.c srcs/reverse_rotate.c \
		srcs/utils_big_one.c srcs/utils_big_two.c srcs/utils_medium.c \
		srcs/utils_one.c srcs/utils_two.c \
		srcs/sort_three.c srcs/medium_sort.c srcs/big_sort.c \
		srcs/free.c

BONUS = bonus/main.c \
		bonus/get_next_line_utils.c bonus/get_next_line.c \
		srcs/create_list.c srcs/check_error.c \
		srcs/swap.c srcs/push.c srcs/rotate.c srcs/reverse_rotate.c \
		srcs/utils_big_one.c srcs/utils_big_two.c srcs/utils_medium.c \
		srcs/utils_one.c srcs/utils_two.c \
		srcs/sort_three.c srcs/medium_sort.c srcs/big_sort.c \
		srcs/free.c

OBJS = $(SRCS:.c=.o)
B_OBJS = $(BONUS:.c=.o)

CC = gcc
CFLAGS = -g -Wall -Wextra -Werror

NAME = push_swap

LIB_DIRS = -Lft_printf -Llibft
LIBS = -lftprintf -lft
INCLUDES = -Ift_printf -Ilibft

GREEN = \033[1;32m
YELLOW = \033[1;33m
BLUE = \033[1;34m
RED = \033[1;31m
RESET = \033[0m

all: $(NAME)

%.o: %.c
	@echo "$(BLUE)Compiling $<...$(RESET)"
	@$(CC) $(CFLAGS) $(INCLUDES) -O3 -c $< -o $@

$(NAME): $(OBJS)
	@$(MAKE) --no-print-directory -C ft_printf
	@$(MAKE) --no-print-directory -C libft
	@echo "$(YELLOW)Linking objects...$(RESET)"
	@$(CC) $(OBJS) $(LIB_DIRS) $(LIBS) -o $(NAME)
	@echo "$(GREEN)Mandatory compilation completed successfully!$(RESET)"

bonus: $(B_OBJS)
	@$(MAKE) --no-print-directory -C ft_printf
	@$(MAKE) --no-print-directory -C libft
	@echo "$(YELLOW)Linking objects...$(RESET)"
	@$(CC) $(B_OBJS) $(LIB_DIRS) $(LIBS) -o $(NAME)
	@echo "$(GREEN)Bonus compilation completed successfully!$(RESET)"

clean:
	@rm -f $(OBJS) $(B_OBJS)
	@$(MAKE) --no-print-directory -C ft_printf clean
	@$(MAKE) --no-print-directory -C libft clean
	@echo "$(GREEN)Cleaning done.$(RESET)"

fclean: clean
	@rm -f $(NAME)
	@$(MAKE) --no-print-directory -C ft_printf fclean
	@$(MAKE) --no-print-directory -C libft fclean
	@echo "$(GREEN)Full clean done.$(RESET)"

re: fclean all

.PHONY: all clean fclean re bonus
