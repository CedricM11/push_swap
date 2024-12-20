/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cedmarti <cedmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 08:08:44 by cedmarti          #+#    #+#             */
/*   Updated: 2024/12/18 17:43:20 by cedmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	reverse_rotate(t_node **a)
{
	t_node	*first;
	t_node	*last;
	t_node	*before_last;

	if (!a || !(*a) || !(*a)->next)
		return ;
	first = *a;
	last = *a;
	while (last->next)
		last = last->next;
	before_last = last->prev;
	before_last->next = NULL;
	last->prev = NULL;
	last->next = first;
	first->prev = last;
	*a = last;
}

void	rra(t_node **a)
{
	reverse_rotate(a);
	ft_printf("rra\n");
}

void	rrb(t_node **b)
{
	reverse_rotate(b);
	ft_printf("rrb\n");
}

void	reverse_rotate_both(t_node **a, t_node **b)
{
	reverse_rotate(a);
	reverse_rotate(b);
	ft_printf("rrr\n");
}
