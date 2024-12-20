/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cedmarti <cedmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 08:06:37 by cedmarti          #+#    #+#             */
/*   Updated: 2024/12/20 17:39:17 by cedmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	end_program(void)
{
	ft_putstr_fd("Error\n", 2);
	exit (1);
}

static long	ft_atol(const char *str)
{
	long	i;
	long	res;
	long	signe;

	i = 0;
	res = 0;
	signe = 1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '+')
		i++;
	else if (str[i] == '-')
	{
		signe = -1;
		i++;
	}
	if (str[i] < '0' || str[i] > '9')
		end_program();
	while (str[i] >= '0' && str[i] <= '9')
		res = (res * 10) + (str[i++] - 48);
	if (str[i] != '\0')
		end_program();
	return (res * signe);
}

static void	init_node(long nbr, t_node *new)
{
	new->value = nbr;
	new->index = -1;
	new->push_cost = -1;
	new->above_mediane = false;
	new->cheapest = false;
	new->target = NULL;
	new->next = NULL;
	new->prev = NULL;
}

static void	append_node(char *str, t_node **a)
{
	long	nbr;
	t_node	*current;
	t_node	*new;

	nbr = ft_atol(str);
	if (nbr > INT_MAX || nbr < INT_MIN)
	{
		ft_putstr_fd("Error\n", 2);
		exit (1);
	}
	new = malloc(sizeof(t_node));
	if (!new)
		return ;
	init_node(nbr, new);
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

void	create_list(int ac, char **av, t_node **a)
{
	int	i;

	check_syntaxe(av);
	if (ac == 2)
	{
		av = ft_split(av[1], 32);
		i = 0;
		while (av[i])
		{
			append_node(av[i], a);
			i++;
		}
		free_split(av);
	}
	else
	{
		i = 1;
		while (av[i])
		{
			append_node(av[i], a);
			i++;
		}
	}
	has_duplicates(*a);
}
