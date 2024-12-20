/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_big_two.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cedmarti <cedmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 17:43:34 by cedmarti          #+#    #+#             */
/*   Updated: 2024/12/20 17:44:27 by cedmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	bubble_sort(int *arr, int len)
{
	int	i;
	int	j;
	int	tmp;

	i = 0;
	while (i < len - 1)
	{
		j = 0;
		while (j < len - i - 1)
		{
			if (arr[j] > arr[j + 1])
			{
				tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
			}
			j++;
		}
		i++;
	}
}

int	find_mediane_tab(t_node *a)
{
	int	*value;
	int	mediane;
	int	len;

	value = copy_list(a);
	len = list_len(a);
	bubble_sort(value, len);
	if (len % 2 == 0)
		mediane = value[(len - 1) / 2];
	else
		mediane = value[len / 2];
	free(value);
	return (mediane);
}

t_node	*find_mediane_list(t_node *a)
{
	t_node	*mediane;
	int		mediane_value;

	mediane = NULL;
	mediane_value = find_mediane_tab(a);
	while (a)
	{
		if (a->value == mediane_value)
			mediane = a;
		a = a->next;
	}
	return (mediane);
}

void	push_median_to_b(t_node **a, t_node **b)
{
	t_node	*mediane;

	mediane = find_mediane_list(*a);
	find_index(*a);
	if (mediane->above_mediane)
	{
		while (mediane != *a)
			ra(a);
	}
	else
	{
		while (mediane != *a)
			rra(a);
	}
	pb(a, b);
}

void	push_all_except_highest(t_node **a, t_node **b)
{
	t_node	*highest;
	t_node	*second_highest;
	t_node	*third_highest;
	t_node	*mediane_node;

	mediane_node = find_mediane_list(*a);
	push_median_to_b(a, b);
	highest = find_highest(a);
	second_highest = find_second_highest(a);
	third_highest = find_third_highest(a);
	while (list_len(*a) > 3)
	{
		if ((*a)->value == highest->value
			|| (*a)->value == second_highest->value
			|| (*a)->value == third_highest->value)
		{
			ra(a);
			continue ;
		}
		pb(a, b);
		if ((*b)->value < mediane_node->value)
			rb(b);
	}
}
