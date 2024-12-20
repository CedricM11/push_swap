/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cedmarti <cedmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 08:07:22 by cedmarti          #+#    #+#             */
/*   Updated: 2024/12/18 17:43:12 by cedmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	push(t_node **src, t_node **dest)
{
	t_node	*first_src;
	t_node	*second_src;
	t_node	*first_dest;

	if (!src || !(*src))
		return ;
	first_src = *src;
	second_src = first_src->next;
	*src = second_src;
	if (second_src)
		second_src->prev = NULL;
	first_dest = *dest;
	if (first_dest)
		first_dest->prev = first_src;
	first_src->next = first_dest;
	first_src->prev = NULL;
	*dest = first_src;
}

void	pa(t_node **b, t_node **a)
{
	push(b, a);
	ft_printf("pa\n");
}

void	pb(t_node **a, t_node **b)
{
	push(a, b);
	ft_printf("pb\n");
}
