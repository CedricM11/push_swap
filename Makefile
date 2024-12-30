# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cedmarti <cedmarti@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/13 10:05:31 by cedmarti          #+#    #+#              #
#    Updated: 2024/12/30 10:57:57 by cedmarti         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


COMMON_SRCS =	srcs/create_list.c srcs/check_error.c \
				srcs/swap.c srcs/push.c srcs/rotate.c srcs/reverse_rotate.c \
				srcs/utils_big_one.c srcs/utils_big_two.c srcs/utils_medium.c \
				srcs/utils_one.c srcs/utils_two.c \
				srcs/sort_three.c srcs/medium_sort.c srcs/big_sort.c \
				srcs/free.c

MAIN =			srcs/main.c

BONUS = 		bonus/bonus_utils.c \
				bonus/get_next_line_utils.c bonus/get_next_line.c \

BONUS_MAIN =	bonus/main.c

OBJS =				$(COMMON_SRCS:.c=.o)
MANDATORY_OBJS =	$(OBJS) $(MAIN:.c=.o)

B_OBJS =			$(BONUS:.c=.o)
BONUS_OBJS =		$(OBJS) $(B_OBJS) $(BONUS_MAIN:.c=.o)

CC = gcc
CFLAGS = -g -Wall -Wextra -Werror

NAME = push_swap
B_NAME = checker

LIB_DIRS = -Lft_printf -Llibft
LIBS = -lftprintf -lft
INCLUDES = -Ift_printf -Ilibft

GREEN = \033[1;32m
YELLOW = \033[1;33m
BLUE = \033[1;34m
RED = \033[1;31m
RESET = \033[0m

all: $(NAME)

bonus: $(B_NAME)

%.o: %.c
	@echo "$(BLUE)Compiling $<...$(RESET)"
	@$(CC) $(CFLAGS) $(INCLUDES) -O3 -c $< -o $@

$(NAME): $(MANDATORY_OBJS)
	@$(MAKE) --no-print-directory -C ft_printf
	@$(MAKE) --no-print-directory -C libft
	@echo "$(YELLOW)Linking objects...$(RESET)"
	@$(CC) $(MANDATORY_OBJS) $(LIB_DIRS) $(LIBS) -o $(NAME)
	@echo "$(GREEN)Mandatory compilation completed successfully!$(RESET)"

$(B_NAME): $(BONUS_OBJS)
	@$(MAKE) --no-print-directory -C ft_printf
	@$(MAKE) --no-print-directory -C libft
	@echo "$(YELLOW)Linking objects...$(RESET)"
	@$(CC) $(BONUS_OBJS) $(LIB_DIRS) $(LIBS) -o $(B_NAME)
	@echo "$(GREEN)Bonus compilation completed successfully!$(RESET)"

clean:
	@rm -f $(OBJS) $(MANDATORY_OBJS) $(BONUS_OBJS)
	@$(MAKE) --no-print-directory -C ft_printf clean
	@$(MAKE) --no-print-directory -C libft clean
	@echo "$(GREEN)Cleaning done.$(RESET)"

fclean: clean
	@rm -f $(NAME) $(B_NAME)
	@$(MAKE) --no-print-directory -C ft_printf fclean
	@$(MAKE) --no-print-directory -C libft fclean
	@echo "$(GREEN)Full clean done.$(RESET)"

re: fclean all

.PHONY: all clean fclean re bonus
