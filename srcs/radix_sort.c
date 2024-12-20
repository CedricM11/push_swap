#include "../push_swap.h"

int get_max_value(t_node *stack)
{
    int max_value;

    if (!stack) // Si la pile est vide
        return (0); // Ou une valeur indicative spécifique

    max_value = stack->value; // Initialiser avec la première valeur
    while (stack)
    {
        if (stack->value > max_value) // Comparer chaque valeur avec le max actuel
            max_value = stack->value;
        stack = stack->next; // Passer au nœud suivant
    }
    return max_value; // Retourner la plus grande valeur
}


void radix_sort(t_node **a, t_node **b, int size)
{
    int max_value = get_max_value(*a);
    int max_bits = 0;
	int	nb_move = 0;

    // Trouver le nombre de bits nécessaires pour représenter max_value
    while ((max_value >> max_bits) != 0)
        max_bits++;

    for (int bit = 0; bit < max_bits; bit++)
    {
        for (int i = 0; i < size; i++)
        {
            if ((((*a)->value >> bit) & 1) == 0)
			{
                push(a, b); // Si le bit est 0, déplacer dans b
				nb_move++;
			}
            else
			{
                rotate(a); // Si le bit est 1, garder dans a et faire une rotation
				nb_move++;
			}
        }

        // Ramener les éléments de b dans a
        while (*b)
		{
            push(b, a);
			nb_move++;
		}
    }
	ft_printf("\nNombre total d'operations : [%d]\n", nb_move);
}
