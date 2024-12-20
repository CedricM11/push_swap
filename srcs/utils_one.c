#include "../push_swap.h"

int	list_len(t_node *a)
{
	int	i;

	i = 0;
	while (a)
	{
		i++;
		a = a->next;
	}
	return (i);
}

t_node	*find_highest(t_node *b)
{
	t_node	*highest;

	highest = b;
	while (b)
	{
		if (b->value > highest->value)
			highest = b;
		b = b->next;
	}
	return (highest);
}

void	find_target_in_b(t_node *a, t_node *b)
{
	int		closest_smaller;
	t_node	*target;
	t_node	*current;

	while (a)
	{
		closest_smaller = INT_MIN;
		target = NULL;
		current = b;
		while (current)
		{
			if (current->value < a->value && current->value > closest_smaller)
			{
				closest_smaller = current->value;
				target = current;
			}
			current = current->next;
		}
		if (target == NULL)
			a->target = find_highest(b);
		else
			a->target = target;
		a = a->next;
	}
}

void	find_index(t_node *lst)
{
	int	index;
	int	len_lst;

	index = 0;
	len_lst = list_len(lst);
	while (lst)
	{
		lst->index = index;
		if (index <= len_lst / 2)
			lst->above_mediane = true;
		else
			lst->above_mediane = false;
		lst = lst->next;
		index++;
	}
}

void	find_push_cost(t_node *a, t_node *b)
{
	int	len_a;
	int	len_b;

	len_a = list_len(a);
	len_b = list_len(b);
	while (a)
	{
		a->push_cost = a->index;
		if (!a->above_mediane)
			a->push_cost  = len_a - a->index;
		if (a->target->above_mediane)
			a->push_cost += a->target->index;
		else
			a->push_cost += len_b - a->target->index;
		printf("Node %d push_cost: %d\n", a->value, a->push_cost);
		a = a->next;
	}
}

t_node *find_cheapest_in_a(t_node *a)
{
    t_node *cheapest_node = NULL;

    // Vérifie si la liste est vide
    if (a == NULL)
        return NULL;

    // Parcours la liste et trouve le nœud avec le push_cost le plus bas
    while (a)
    {
        if (cheapest_node == NULL || a->push_cost < cheapest_node->push_cost)
        {
            cheapest_node = a;  // Met à jour le nœud avec le coût le plus bas
        }
        a = a->next;  // Passe au nœud suivant
    }

    return cheapest_node;
}

t_node	*get_cheapest_node(t_node *a)
{
	if (a == NULL)
	{
		printf("Error: list is NULL\n");
		return (NULL);
	}
	while (a)
	{
		printf("Node %d: cheapest = %d\n", a->value, a->cheapest);
		if (a->cheapest)
			return (a);
		a = a->next;
	}
	printf("Warning: no node marked as cheapest\n");
	return (NULL);
}

void	rotation_stack_a(t_node **a, t_node *head)
{
	while (*a != head)
	{
		if (head->above_mediane)
			rotate(a);
		else
			reverse_rotate(a);
	}
}

void	rotation_stack_b(t_node **b, t_node *head)
{
	while (*b != head)
	{
		if (head->above_mediane)
			rotate(b);
		else
			reverse_rotate(b);
	}
}

void	update_node(t_node *a, t_node *b)
{
	find_index(a);
	printf("index de a : [%d]\n", a->index);
	find_index(b);
	printf("index de b : [%d]\n", b->index);
	find_target_in_b(a, b);
	printf("target node : [%p]\n", a->target);
	find_push_cost(a, b);
	printf("push cost du node : [%d]\n", a->push_cost);
}

void	update_list(t_node **a, t_node **b)
{
	t_node	*cheapest_node;

	cheapest_node = find_cheapest_in_a(*a);
	if (!cheapest_node) {
    	printf("Error: invalid cheapest node or target\n");
    	return;
	}
	rotation_stack_a(a, cheapest_node);
	rotation_stack_b(b, cheapest_node->target);
	push(a, b);
}
