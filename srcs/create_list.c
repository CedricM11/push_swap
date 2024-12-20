#include "../push_swap.h"

void	init_node(int nbr, t_node *new)
{
	new->value = nbr;
	new->index = -1;
	new->push_cost = -1;
	new->above_mediane = false;
	new->cheapest = false;
	new->target = NULL;
	new->prev = NULL;
	new->next = NULL;
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

	if (ac == 2)
	{
		i = 0;
		av = ft_split(av[1], 32);
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
}
