/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cedricmartin <cedricmartin@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 15:35:15 by cedmarti          #+#    #+#             */
/*   Updated: 2024/12/14 17:53:01 by cedricmarti      ###   ########.fr       */
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

void	swap(t_node **a)
{
	t_node	*first;
	t_node	*second;

	if (!a || !(*a) || !(*a)->next)
		return ;
	first = *a;
	second = first->next;
	first->next = second->next;
	if (second->next != NULL)
		second->next->prev = first;
	second->prev = NULL;
	second->next = first;
	first->prev = second;
	*a = second;
}

void	push(t_node **a, t_node **b)
{
	t_node	*first;
	t_node	*second;
	t_node	*first_b;

	if (!a || !(*a))
		return ;
	first = *a;
	second = first->next;
	*a = second;
	if (second)
		second->prev = NULL;
	first_b = *b;
	if (first_b)
		first_b->prev = first;
	first->next = first_b;
	first->prev = NULL;
	*b = first;
}

void	append_node(char *str, t_node **a)
{
	int		nbr;
	t_node	*current;
	t_node	*new;

	nbr = ft_atoi(str);
	new = malloc(sizeof(t_node));
	if (!new)
		return ;
	new->value = nbr;
	new->prev = NULL;
	new->next = NULL;
	if (*a == NULL)
		*a = new;
	else
	{
		current = *a;
		while (current->next)
			current = current->next;
		current->next = new;
		new->prev = current;
	}
}

void	free_list(t_node *a)
{
	t_node	*tmp;

	while (a)
	{
		tmp = a;
		a = a->next;
		free(tmp);
	}
}

void	free_split(char **av)
{
	int	i;

	i = 0;
	while (av[i])
	{
		free(av[i]);
		i++;
	}
	free(av);
}

int	main(int ac, char **av)
{
	t_node	*a;
	t_node	*b;

	a = NULL;
	b = NULL;
	if (ac == 2)
	{
		av = ft_split(av[1], 32);
		for (int i = 0; av[i]; i++)
			append_node(av[i], &a);
		free_split(av);
	}
	else
	{
		for (int i = 1; av[i]; i++)
			append_node(av[i], &a);
	}
	print_list(a);
	print_list(b);
	push(&a, &b);
	print_list(a);
	print_list(b);
	free_list(a);
	free_list(b);
	return (0);
}
