/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_two.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cedmarti <cedmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 10:17:43 by cedmarti          #+#    #+#             */
/*   Updated: 2024/12/20 17:42:01 by cedmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	list_len(t_node *a)
{
	int	len;

	len = 0;
	while (a)
	{
		len++;
		a = a->next;
	}
	return (len);
}

void	find_index(t_node *a)
{
	int	i;
	int	mediane;

	i = 0;
	mediane = list_len(a) / 2;
	if (a == NULL)
		return ;
	while (a)
	{
		a->index = i;
		if (i <= mediane)
			a->above_mediane = true;
		else
			a->above_mediane = false;
		a = a->next;
		i++;
	}
}

void	find_target(t_node *a, t_node *b)
{
	t_node	*current;
	t_node	*target;
	long	best_match;

	while (b)
	{
		best_match = LONG_MAX;
		target = NULL;
		current = a;
		while (current)
		{
			if (current->value > b->value && current->value < best_match)
			{
				best_match = current->value;
				target = current;
			}
			current = current->next;
		}
		if (target == NULL)
			b->target = find_smallest(&a);
		else
			b->target = target;
		b = b->next;
	}
}

void	find_push_cost(t_node *a, t_node *b)
{
	int	len_a;
	int	len_b;

	len_a = list_len(a);
	len_b = list_len(b);
	while (b)
	{
		b->push_cost = b->index;
		if (!b->above_mediane)
			b->push_cost = len_b - b->index;
		if (b->target->above_mediane)
			b->push_cost += b->target->index;
		else
			b->push_cost += len_a - b->target->index;
		b = b->next;
	}
}

t_node	*find_cheapest(t_node *b)
{
	t_node	*cheapest_node;

	cheapest_node = NULL;
	if (b == NULL)
		return (NULL);
	while (b)
	{
		if (cheapest_node == NULL || b->push_cost < cheapest_node->push_cost)
			cheapest_node = b;
		b = b->next;
	}
	return (cheapest_node);
}
