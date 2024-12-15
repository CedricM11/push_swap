#include "../push_swap.h"

void	push(t_node **src, t_node **dest)
{
	t_node	*first_src;
	t_node	*second_src;
	t_node	*first_dest;

	if (!src || !(*src))
		return ;
	first_src = *src;
	second_src = first_src->next;
	*src = second_src;
	if (second_src)
		second_src->prev = NULL;
	first_dest = *dest;
	if (first_dest)
		first_dest->prev = first_src;
	first_src->next = first_dest;
	first_src->prev = NULL;
	*dest = first_src;
}
