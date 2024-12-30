/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cedmarti <cedmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 17:25:51 by cedmarti          #+#    #+#             */
/*   Updated: 2024/12/30 13:36:45 by cedmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	check_syntaxe(char **av)
{
	int	i;
	int	j;

	i = 1;
	while (av[i])
	{
		j = 0;
		while (av[i][j])
		{
			if (!ft_isdigit(av[i][j]) && av[i][j] != ' '
				&& av[i][j] != '-' && av[i][j] != '+')
			{
				ft_putstr_fd("Error\n", 2);
				exit (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

int	has_duplicates(t_node *list)
{
	t_node	*current;
	t_node	*checker;

	if (!list)
		return (0);
	current = list;
	while (current)
	{
		checker = current->next;
		while (checker)
		{
			if (current->value == checker->value)
			{
				ft_putstr_fd("Error\n", 2);
				free_list(list);
				exit (1);
			}
			checker = checker->next;
		}
		current = current->next;
	}
	return (0);
}
