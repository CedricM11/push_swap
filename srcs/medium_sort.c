/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cedmarti <cedmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 14:27:18 by cedmarti          #+#    #+#             */
/*   Updated: 2024/12/20 14:31:53 by cedmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	update_node_medium_start(t_node *a, t_node *b)
{
	find_index(a);
	find_index(b);
	find_target_in_b(a, b);
	find_push_cost_start(a, b);
}

void	update_list_medium_start(t_node **a, t_node **b)
{
	t_node	*cheapest_node;

	cheapest_node = find_cheapest_in_a(*a);
	if (cheapest_node->above_mediane && cheapest_node->target->above_mediane)
	{
		while (*b != cheapest_node->target && *a != cheapest_node)
		{
			rotate_both(a, b);
			find_index(*a);
			find_index(*b);
		}
	}
	else if (!cheapest_node->above_mediane
		&& !cheapest_node->target->above_mediane)
	{
		while (*b != cheapest_node->target && *a != cheapest_node)
		{
			reverse_rotate_both(a, b);
			find_index(*a);
			find_index(*b);
		}
	}
	rotation_stack_a(a, cheapest_node);
	rotation_stack_b(b, cheapest_node->target);
	pb(a, b);
}

void	update_node_medium(t_node *a, t_node *b)
{
	find_index(a);
	find_index(b);
	find_target(a, b);
}

void	update_list_medium(t_node **a, t_node **b)
{
	rotation_stack_a(a, (*b)->target);
	pa(b, a);
}

void	medium_sort(t_node **a, t_node **b)
{
	int		len_a;
	t_node	*smallest;

	pb(a, b);
	pb(a, b);
	len_a = list_len(*a);
	while (len_a > 3)
	{
		update_node_medium_start(*a, *b);
		update_list_medium_start(a, b);
		len_a--;
	}
	sort_three(a);
	while (*b)
	{
		update_node_medium(*a, *b);
		update_list_medium(a, b);
	}
	smallest = find_smallest(a);
	if (smallest->above_mediane)
		while (*a != smallest)
			ra(a);
	else
		while (*a != smallest)
			rra(a);
}
