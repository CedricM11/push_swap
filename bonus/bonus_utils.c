/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cedmarti <cedmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 10:59:39 by cedmarti          #+#    #+#             */
/*   Updated: 2024/12/30 13:27:46 by cedmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include "../bonus/get_next_line.h"

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i])
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	return (0);
}

void	quiet_swap_both(t_node **a, t_node **b)
{
	swap(a);
	swap(b);
}

void	quiet_rotate_both(t_node **a, t_node **b)
{
	rotate(a);
	rotate(b);
}

void	quiet_rev_rotate_both(t_node **a, t_node **b)
{
	reverse_rotate(a);
	reverse_rotate(b);
}

void	wrong_move(t_node *a, t_node *b, char *move)
{
	free(move);
	free_list(a);
	free_list(b);
	ft_putstr_fd("Error\n", 2);
	exit (1);
}
