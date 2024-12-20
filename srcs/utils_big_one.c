/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_big_one.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cedmarti <cedmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 07:35:25 by cedmarti          #+#    #+#             */
/*   Updated: 2024/12/20 17:44:22 by cedmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_node	*find_smallest(t_node **a)
{
	t_node	*smallest;
	t_node	*current;

	if (!a || !*a)
		return (NULL);
	smallest = *a;
	current = *a;
	while (current)
	{
		if (current->value < smallest->value)
			smallest = current;
		current = current->next;
	}
	return (smallest);
}

t_node	*find_highest(t_node **a)
{
	t_node	*highest;
	t_node	*current;

	if (!a || !*a)
		return (NULL);
	highest = *a;
	current = *a;
	while (current)
	{
		if (current->value > highest->value)
			highest = current;
		current = current->next;
	}
	return (highest);
}

t_node	*find_second_highest(t_node **a)
{
	t_node	*highest;
	t_node	*second_highest;
	t_node	*current;

	if (!a || !*a)
		return (NULL);
	highest = find_highest(a);
	second_highest = NULL;
	current = *a;
	while (current)
	{
		if (current != highest && (!second_highest
				|| current->value > second_highest->value))
			second_highest = current;
		current = current->next;
	}
	return (second_highest);
}

t_node	*find_third_highest(t_node **a)
{
	t_node	*highest;
	t_node	*second_highest;
	t_node	*third_highest;
	t_node	*current;

	if (!a || !*a)
		return (NULL);
	highest = find_highest(a);
	second_highest = find_second_highest(a);
	third_highest = NULL;
	current = *a;
	while (current)
	{
		if (current != highest && current != second_highest
			&& (!third_highest || current->value > third_highest->value))
			third_highest = current;
		current = current->next;
	}
	return (third_highest);
}

int	*copy_list(t_node *a)
{
	t_node	*current;
	int		*value;
	int		len;
	int		i;

	len = list_len(a);
	value = malloc(sizeof(int) * len);
	current = a;
	i = 0;
	while (i < len)
	{
		value[i] = current->value;
		current = current->next;
		i++;
	}
	return (value);
}
