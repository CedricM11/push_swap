/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cedmarti <cedmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 08:07:49 by cedmarti          #+#    #+#             */
/*   Updated: 2024/12/18 17:43:29 by cedmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	rotate(t_node **a)
{
	t_node	*first;
	t_node	*last;
	t_node	*second;

	if (!a || !(*a) || !(*a)->next)
		return ;
	first = *a;
	second = first->next;
	last = *a;
	while (last->next)
		last = last->next;
	second->prev = NULL;
	first->next = NULL;
	first->prev = last;
	last->next = first;
	*a = second;
}

void	ra(t_node **a)
{
	rotate(a);
	ft_printf("ra\n");
}

void	rb(t_node **b)
{
	rotate(b);
	ft_printf("rb\n");
}

void	rotate_both(t_node **a, t_node **b)
{
	rotate(a);
	rotate(b);
	ft_printf("rr\n");
}
