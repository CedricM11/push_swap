/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cedmarti <cedmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 15:35:15 by cedmarti          #+#    #+#             */
/*   Updated: 2024/12/20 14:48:50 by cedmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	main(int ac, char **av)
{
	t_node	*a;
	t_node	*b;

	a = NULL;
	b = NULL;
	if (ac < 2 || av[1][0] == '\0')
		return (1);
	create_list(ac, av, &a);
	if (is_sorted(a) == 0)
	{
		if (list_len(a) == 2)
			sa(&a);
		else if (list_len(a) == 3)
			sort_three(&a);
		else if (list_len(a) <= 200)
			medium_sort(&a, &b);
		else
			big_sort(&a, &b);
	}
	free_list(a);
	free_list(b);
	return (0);
}
