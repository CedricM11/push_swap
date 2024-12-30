/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cedmarti <cedmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 11:42:56 by cedmarti          #+#    #+#             */
/*   Updated: 2024/12/30 13:27:28 by cedmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include "../bonus/get_next_line.h"

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

void	make_move(t_node **a, t_node **b, char *move)
{
	if (ft_strcmp(move, "sa\n") == 0)
		swap(a);
	else if (ft_strcmp(move, "sb\n") == 0)
		swap(b);
	else if (ft_strcmp(move, "ss") == 0)
		quiet_swap_both(a, b);
	else if (ft_strcmp(move, "pa\n") == 0)
		push(b, a);
	else if (ft_strcmp(move, "pb\n") == 0)
		push(a, b);
	else if (ft_strcmp(move, "ra\n") == 0)
		rotate(a);
	else if (ft_strcmp(move, "rb\n") == 0)
		rotate(b);
	else if (ft_strcmp(move, "rr\n") == 0)
		quiet_rotate_both(a, b);
	else if (ft_strcmp(move, "rra\n") == 0)
		reverse_rotate(a);
	else if (ft_strcmp(move, "rrb\n") == 0)
		reverse_rotate(b);
	else if (ft_strcmp(move, "rrr\n") == 0)
		quiet_rev_rotate_both(a, b);
	else
		wrong_move(*a, *b, move);
}

void	read_move(t_node **a, t_node **b)
{
	char	*move;

	while (1)
	{
		move = get_next_line(0);
		if (move == NULL)
			break ;
		else
			make_move(a, b, move);
		free(move);
	}
}

void	checker(t_node *a, t_node *b)
{
	if (is_sorted(a) && b == NULL)
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
}

int	main(int ac, char **av)
{
	t_node	*bonus_a;
	t_node	*bonus_b;

	bonus_a = NULL;
	bonus_b = NULL;
	if (ac < 2 || av[1][0] == '\0')
		return (1);
	create_list(ac, av, &bonus_a);
	read_move(&bonus_a, &bonus_b);
	print_list(bonus_a);
	checker(bonus_a, bonus_b);
	free_list(bonus_a);
	free_list(bonus_b);
}
