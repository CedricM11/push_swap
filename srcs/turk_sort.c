#include "../push_swap.h"

/*
- si A est plus grand que 3 Push 2 nodes dans stack b
- On continu de push dans b tout en triant
	- trouver les target nodes dans B
		=> closest smaller
		=> si pas de smaller value, target node est le plus grand nombre
	- trouver le cout de push pour deduire le cheapest node
		=> push cost = nombre d'operation pour mettre cheapest en tete + nombre d'operation pour mettre cheapest->target en tete
		(si push cost = 0 on peut arreter le calcule et faire le push)
	=> pb
- sort_three dans A (il rest seulement 3 nodes)
- Renvoyer les nodes dans A jusqu'à ce que B soit vide
	- trouver les target nodes dans A
		=> closest bigger
		=> si pas de bigger value, target node est le plus petit nombre
	- Push les nodes dans A (push toujours celui qui est en tête dans B)
		=> si target_node du node B est au dessus de la mediane on rotate jusqu'a ce que target_node du B soit en tete de A
		=> si target_node du node b est en dessous de la mediane on reverse rotate jusqu'a ce que target node du B soit en tete de A
- Quand B es vide, on cherhe le node avec la value la plus basse
	=> si smallest est au dessus de la mediane on rotate jusqu'a ce que smallest soit en tete
	=> si smallest est en dessous de la mediane on reverse rotate jusqu'a ce qu'il soit en tete
*/

void	turk_sort(t_node **a, t_node **b)
{
	int	len_a;

	push(a, b);
	ft_printf("pb\n");
	push(a, b);
	ft_printf("pb\n");
	len_a = list_len(*a);
	ft_printf("Pile A après push:\n");
	print_list(*a);
	ft_printf("Pile B après push:\n");
	print_list(*b);
	ft_printf("%d\n", len_a);
	while (len_a > 3)
	{
		update_node(*a, *b);
		update_list(a, b);
		len_a--;
	}
}