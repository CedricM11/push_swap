/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cedmarti <cedmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 11:42:56 by cedmarti          #+#    #+#             */
/*   Updated: 2024/12/26 15:27:05 by cedmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include "../bonus/get_next_line.h"

/*
	- faire une copie de A
	- faire le push_swap
	- Recuperer les moves sur stdin
	- executer les moves sur la copie
	- si A trie et B null, qfficher OK
	- Sinon afficher KO
	- Free la copie de A
*/

void	print_list(t_node *a)
{
	t_node	*current;

	current = a;
	if (current == NULL)
		ft_printf("[liste vide]");
	while (current)
	{
		ft_printf("value : [%d]\n", current->value);
		current = current->next;
	}
}

void	ft_push_swap(t_node **a, t_node **b)
{
	if (is_sorted(*a) == 0)
	{
		if (list_len(*a) == 2)
			sa(a);
		else if (list_len(*a) == 3)
			sort_three(a);
		else if (list_len(*a) <= 200)
			medium_sort(a, b);
		else
			big_sort(a, b);
	}
}

void	read_move()
{
	char	*move;

	move = get_next_line(0);
	ft_printf("move : [%s]\n", move);
	/*while (1)
	{
		move = get_next_line(0);
		if (move == NULL)
			break ;
		else
			make_move(a, b, move);
	}*/
	free(move);
}

int	main(int ac, char **av)
{
	t_node	*a;
	t_node	*b;
	t_node	*copy_a;
	t_node	*copy_b;

	a = NULL;
	b = NULL;
	copy_a = NULL;
	copy_b = NULL;
	create_list(ac, av, &a);
	create_list(ac, av, &copy_a);
	ft_push_swap(&a, &b);
	read_move();
	free_list(a);
	free_list(copy_a);
	free_list(copy_b);
	free_list(b);
}
