/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cedmarti <cedricmartin@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 15:31:44 by cedmarti          #+#    #+#             */
/*   Updated: 2024/12/17 22:38:27 by cedmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "ft_printf/ft_printf.h"
# include "libft/libft.h"
# include <stdio.h>
# include <stdbool.h>
# include <limits.h>

typedef struct s_node
{
	int				value;
	int				index;
	int				push_cost;
	bool			above_mediane;
	bool			cheapest;
	struct s_node	*target;
	struct s_node	*next;
	struct s_node	*prev;
}				t_node;

// create list
void	print_list(t_node *a);
void	append_node(char *str, t_node **a);
void	create_list(int ac, char **av, t_node **a);

// moves
void	swap(t_node **a);
void	swap_both(t_node **a, t_node **b);
void	push(t_node **src, t_node **dest);
void	rotate(t_node **a);
void	rotate_both(t_node **a, t_node **b);
void	reverse_rotate(t_node **a);
void	reverse_rotate_both(t_node **a, t_node **b);

// utils
int		list_len(t_node *a);
t_node	*find_highest(t_node *b);
void	find_target_in_b(t_node *a, t_node *b);
void	find_index(t_node *lst);
void	find_push_cost(t_node *a, t_node *b);
t_node	*get_cheapest_node(t_node *a);
t_node	*get_cheapest_node(t_node *a);
void	rotation_stack_a(t_node **a, t_node *head);
void	rotation_stack_b(t_node **b, t_node *head);
void	update_node(t_node *a, t_node *b);
void	update_list(t_node **a, t_node **b);

// sort
void	insertion_sort(t_node **a, t_node **b);
void	radix_sort(t_node **a, t_node **b, int size);
void	turk_sort(t_node **a, t_node **b);

// free memory
void	free_list(t_node *a);
void	free_split(char **av);

#endif
