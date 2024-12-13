/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cedmarti <cedmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 08:50:33 by cedmarti          #+#    #+#             */
/*   Updated: 2024/11/06 09:03:00 by cedmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*element;

	if (!new || !lst)
		return ;
	if (*lst == NULL)
	{
		*lst = new;
	}
	else
	{
		element = ft_lstlast(*lst);
		element->next = new;
	}
}
