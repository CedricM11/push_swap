/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_one.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cedmarti <cedmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 17:41:53 by cedmarti          #+#    #+#             */
/*   Updated: 2024/12/20 17:42:37 by cedmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	is_sorted(t_node *list)
{
	while (list->next)
	{
		if (list->value > list->next->value)
			return (0);
		list = list->next;
	}
	return (1);
}

void	rotation_stack_a(t_node **lst, t_node *head)
{
	while (*lst != head)
	{
		if (head->above_mediane)
			ra(lst);
		else
			rra(lst);
	}
}

void	rotation_stack_b(t_node **lst, t_node *head)
{
	while (*lst != head)
	{
		if (head->above_mediane)
			rb(lst);
		else
			rrb(lst);
	}
}

void	update_node(t_node *a, t_node *b)
{
	find_index(a);
	find_index(b);
	find_target(a, b);
	find_push_cost(a, b);
}

void	update_list(t_node **a, t_node **b)
{
	t_node	*cheapest_node;

	cheapest_node = find_cheapest(*b);
	if (cheapest_node->above_mediane && cheapest_node->target->above_mediane)
	{
		while (*a != cheapest_node->target && *b != cheapest_node)
		{
			rotate_both(a, b);
			find_index(*a);
			find_index(*b);
		}
	}
	else if (!cheapest_node->above_mediane
		&& !cheapest_node->target->above_mediane)
	{
		while (*a != cheapest_node->target && *b != cheapest_node)
		{
			reverse_rotate_both(a, b);
			find_index(*a);
			find_index(*b);
		}
	}
	rotation_stack_a(a, cheapest_node->target);
	rotation_stack_b(b, cheapest_node);
	pa(b, a);
}
