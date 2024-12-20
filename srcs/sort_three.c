/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cedmarti <cedmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 17:30:11 by cedmarti          #+#    #+#             */
/*   Updated: 2024/12/18 10:50:12 by cedmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sort_three(t_node **a)
{
	t_node	*first;
	t_node	*second;
	t_node	*highest;

	first = *a;
	second = first->next;
	highest = find_highest(a);
	if (first->value == highest->value)
		ra(a);
	else if (second->value == highest->value)
		rra(a);
	first = *a;
	second = first->next;
	if (first->value > second->value)
		sa(a);
}
