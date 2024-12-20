#include "../push_swap.h"

void    insertion_sort(t_node **a, t_node **b)
{
	int	nb_move;
    t_node *current_a;

	nb_move = 0;
    // Étape 1 : Déplacer les éléments de A vers B en maintenant B triée
    while (*a)
    {
        current_a = *a; // Récupérer le premier élément de A
        if (*b == NULL || current_a->value > (*b)->value)
        {
            // Si B est vide ou le premier élément de A est >= au premier élément de B
            push(a, b); // Déplace le premier élément de A vers le haut de B
			ft_printf("pb\n");
			nb_move++;
        }
        else
        {
            // Trouver la bonne position dans B pour insérer l'élément
            int rotations = 0; // Compter les rotations effectuées
            t_node *start = *b; // Garder la trace du début de B pour éviter de tourner en boucle infinie

            while (*b && current_a->value < (*b)->value)
            {
                rotate(b); // Effectuer une rotation sur B
				ft_printf("rb\n");
				nb_move++;
                rotations++;
                if (*b == start) // Si on revient au point de départ, on a bouclé
                    break;
            }
            push(a, b); // Insérer le premier élément de A dans la bonne position de B
			ft_printf("pb\n");
			nb_move++;

            // Remettre B dans son état initial après insertion
            while (rotations > 0)
            {
                reverse_rotate(b);
				ft_printf("rrb\n");
				nb_move++;
                rotations--;
            }
        }
    }

    // Étape 2 : Déplacer tous les éléments de B vers A dans l'ordre trié
    while (*b)
	{
        push(b, a); // Déplace les éléments de B vers A
		ft_printf("pa\n");
		nb_move++;
	}
	ft_printf("\nNombre total d'operations : [%d]\n", nb_move);
}


