#include "../push_swap.h"

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

void	swap_both(t_node **a, t_node **b)
{
	swap(a);
	swap(b);
}