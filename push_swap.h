/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cedricmartin <cedricmartin@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 15:31:44 by cedmarti          #+#    #+#             */
/*   Updated: 2024/12/15 11:20:18 by cedricmarti      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "ft_printf/ft_printf.h"
# include "libft/libft.h"

typedef struct s_node
{
	int				value;
	struct s_node	*next;
	struct s_node	*prev;
}				t_node;

// create list
void	append_node(char *str, t_node **a);
void	create_list(int ac, char **av, t_node **a);

// moves
void	swap(t_node **a);
void	swap_both(t_node **a, t_node **b);
void	push(t_node **src, t_node **dest);
void	rotate(t_node **a);
void	rotate_both(t_node **a, t_node **b);
void	reverse_rotate(t_node **a);
void	reverse_rotate_both(t_node **a, t_node **b);

// free memory
void	free_list(t_node *a);
void	free_split(char **av);

#endif
