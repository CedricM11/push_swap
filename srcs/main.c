/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cedricmartin <cedricmartin@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 15:35:15 by cedmarti          #+#    #+#             */
/*   Updated: 2024/12/15 11:18:41 by cedricmarti      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	print_node(t_node *a)
{
	ft_printf("value : %d\n", a->value);
	ft_printf("prev  : %p\n", a->prev);
	ft_printf("next  : %p\n", a->next);
}

void	print_list(t_node *a)
{
	int	i;

	if (a == NULL)
		ft_printf("[Liste vide]\n\n");
	i = 1;
	while (a)
	{
		ft_printf("[Node %d]:\n", i);
		print_node(a);
		ft_printf("\n");
		i++;
		a = a->next;
	}
}

int	main(int ac, char **av)
{
	t_node	*a;
	//t_node	*b;

	a = NULL;
	//b = NULL;
	create_list(ac, av, &a);
	print_list(a);
	reverse_rotate(&a);
	print_list(a);
	free_list(a);
	return (0);
}
