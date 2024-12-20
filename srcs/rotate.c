#include "../push_swap.h"

void	rotate(t_node **a)
{
	t_node	*first;
	t_node	*last;
	t_node	*second;

	if (!a || !(*a) || !(*a)->next)
		return ;
	first = *a;
	second = first->next;
	last = *a;
	while (last->next)
		last = last->next;
	second->prev = NULL;
	first->next = NULL;
	first->prev = last;
	last->next = first;
	*a = second;
}

void	rotate_both(t_node **a, t_node **b)
{
	rotate(a);
	rotate(b);
}