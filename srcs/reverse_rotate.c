#include "../push_swap.h"

void	reverse_rotate(t_node **a)
{
	t_node	*first;
	t_node	*last;
	t_node	*before_last;

	if (!a || !(*a) || !(*a)->next)
		return ;
	first = *a;
	last = *a;
	while (last->next)
		last = last->next;
	before_last = last->prev;
	before_last->next = NULL;
	last->prev = NULL;
	last->next = first;
	first->prev = last;
	*a = last;
}

void	reverse_rotate_both(t_node **a, t_node **b)
{
	reverse_rotate(a);
	reverse_rotate(b);
}