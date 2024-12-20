/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cedmarti <cedmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 15:09:53 by cedmarti          #+#    #+#             */
/*   Updated: 2024/12/20 14:15:53 by cedmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	big_sort(t_node **a, t_node **b)
{
	t_node	*smallest;

	push_all_except_highest(a, b);
	if (is_sorted(*a) == 0)
		sort_three(a);
	while (*b)
	{
		update_node(*a, *b);
		update_list(a, b);
	}
	smallest = find_smallest(a);
	if (smallest->above_mediane)
		while (*a != smallest)
			ra(a);
	else
		while (*a != smallest)
			rra(a);
}
