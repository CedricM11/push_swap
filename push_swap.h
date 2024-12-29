/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cedmarti <cedmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 15:31:44 by cedmarti          #+#    #+#             */
/*   Updated: 2024/12/29 16:24:15 by cedmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <stdbool.h>
# include <stdlib.h>
# include <unistd.h>
# include "ft_printf/ft_printf.h"
# include "libft/libft.h"

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

// errors
int		check_syntaxe(char **av);
int		has_duplicates(t_node *list);

// create list
void	create_list(int ac, char **av, t_node **a);

// moves
void	swap(t_node **a);
void	sa(t_node **a);
void	sb(t_node **b);
void	swap_both(t_node **a, t_node **b);
void	push(t_node **src, t_node **dest);
void	pa(t_node **b, t_node **a);
void	pb(t_node **a, t_node **b);
void	rotate(t_node **a);
void	ra(t_node **a);
void	rb(t_node **b);
void	rotate_both(t_node **a, t_node **b);
void	reverse_rotate(t_node **a);
void	rra(t_node **a);
void	rrb(t_node **b);
void	reverse_rotate_both(t_node **a, t_node **b);

// utils
int		is_sorted(t_node *list);
int		list_len(t_node *a);
void	find_index(t_node *a);
void	find_target(t_node *a, t_node *b);
void	find_push_cost(t_node *a, t_node *b);
t_node	*find_cheapest(t_node *a);
t_node	*find_highest(t_node **a);
t_node	*find_second_highest(t_node **a);
t_node	*find_third_highest(t_node **a);
t_node	*find_smallest(t_node **a);
int		*copy_list(t_node *a);
void	bubble_sort(int *arr, int len);
int		find_mediane_tab(t_node *a);
t_node	*find_mediane_list(t_node *a);
void	push_median_to_b(t_node **a, t_node **b);
void	push_all_except_highest(t_node **a, t_node **b);
void	rotation_stack_a(t_node **lst, t_node *head);
void	rotation_stack_b(t_node **lst, t_node *head);
void	update_node(t_node *a, t_node *b);
void	update_list(t_node **a, t_node **b);

// utils medium
void	find_target_in_b(t_node *a, t_node *b);
void	find_push_cost_start(t_node *a, t_node *b);
t_node	*find_cheapest_in_a(t_node *a);

// sort_three
void	sort_three(t_node **a);

// medium_sort
void	update_node_medium_start(t_node *a, t_node *b);
void	update_list_medium_start(t_node **a, t_node **b);
void	update_node_medium(t_node *a, t_node *b);
void	update_list_medium(t_node **a, t_node **b);
void	medium_sort(t_node **a, t_node **b);

// big_sort
void	big_sort(t_node **a, t_node **b);

// free memory
void	free_list(t_node *a);
void	free_split(char **av);

// bonus
int		ft_strcmp(char *s1, char *s2);
void	quiet_swap_both(t_node **a, t_node **b);
void	quiet_rotate_both(t_node **a, t_node **b);
void	quiet_rev_rotate_both(t_node **a, t_node **b);
void	wrong_move(t_node *a, t_node *b);

#endif
