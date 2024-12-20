/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_medium.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cedmarti <cedmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 09:10:01 by cedmarti          #+#    #+#             */
/*   Updated: 2024/12/20 14:36:34 by cedmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	find_target_in_b(t_node *a, t_node *b)
{
	long	closest_smaller;
	t_node	*target;
	t_node	*current;

	while (a)
	{
		closest_smaller = LONG_MIN;
		target = NULL;
		current = b;
		while (current)
		{
			if (current->value < a->value && current->value > closest_smaller)
			{
				closest_smaller = current->value;
				target = current;
			}
			current = current->next;
		}
		if (target == NULL)
			a->target = find_highest(&b);
		else
			a->target = target;
		a = a->next;
	}
}

void	find_push_cost_start(t_node *a, t_node *b)
{
	int	len_a;
	int	len_b;

	len_a = list_len(a);
	len_b = list_len(b);
	while (a)
	{
		a->push_cost = a->index;
		if (!a->above_mediane)
			a->push_cost = len_a - a->index;
		if (a->target->above_mediane)
			a->push_cost += a->target->index;
		else
			a->push_cost += len_b - a->target->index;
		a = a->next;
	}
}

t_node	*find_cheapest_in_a(t_node *a)
{
	t_node	*cheapest_node;

	cheapest_node = NULL;
	if (a == NULL)
		return (NULL);
	while (a)
	{
		if (cheapest_node == NULL || a->push_cost < cheapest_node->push_cost)
			cheapest_node = a;
		a = a->next;
	}
	return (cheapest_node);
}
