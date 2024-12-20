/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cedmarti <cedmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 10:40:06 by cedmarti          #+#    #+#             */
/*   Updated: 2024/11/11 08:36:22 by cedmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*#include <stdio.h>

void print_list(t_list *lst)
{
    while (lst)
    {
        printf("%d -> ", *(int *)lst->content);
        lst = lst->next;
    }
    printf("NULL\n");
}

void *add_five(void *content)
{
	int *a = malloc(sizeof(int));
    *a = (*(int *)content) + 5;
    return (a);
}

void del_content(void *content)
{
    free(content);
}*/

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_lst;
	t_list	*new_element;

	if (!lst || !f || !del)
		return (NULL);
	new_lst = NULL;
	while (lst)
	{
		new_element = ft_lstnew(f(lst->content));
		if (!new_element)
		{
			ft_lstclear(&new_lst, del);
			return (NULL);
		}
		ft_lstadd_back(&new_lst, new_element);
		lst = lst->next;
	}
	return (new_lst);
}

/*int main(void)
{
	int *num1 = malloc(sizeof(int));
    int *num2 = malloc(sizeof(int));
    int *num3 = malloc(sizeof(int));

    if (!num1 || !num2 || !num3)
        return (1); // Erreur d'allocation

    *num1 = 10;
    *num2 = 20;
    *num3 = 30;

    t_list *lst = ft_lstnew(num1);
    ft_lstadd_back(&lst, ft_lstnew(num2));
    ft_lstadd_back(&lst, ft_lstnew(num3));

    // Affichage de la liste initiale
    printf("Liste initiale :\n");
    print_list(lst);

    // Application de ft_lstmap
    t_list *new_lst = ft_lstmap(lst, add_five, del_content);

    // Affichage de la nouvelle liste
    printf("\nNouvelle liste après ft_lstmap :\n");
    print_list(new_lst);

    // Nettoyage de la mémoire
    ft_lstclear(&lst, del_content);
    ft_lstclear(&new_lst, del_content);

	//run this command to test
	//cc -Wall -Wextra -Werror ft_lstmap_bonus.c ft_lstclear_bonus.c
	//ft_lstadd_back_bonus.c ft_lstnew_bonus.c ft_lstlast_bonus.c

    return 0;
}*/
