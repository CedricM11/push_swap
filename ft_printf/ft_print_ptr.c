/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cedmarti <cedmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 08:45:28 by cedmarti          #+#    #+#             */
/*   Updated: 2024/11/19 17:55:19 by cedmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_ptr(unsigned long long num)
{
	if (num >= 16)
	{
		ft_print_ptr(num / 16);
		ft_print_ptr(num % 16);
	}
	else
	{
		if (num < 10)
			ft_putchar_len(num + '0');
		else
			ft_putchar_len(num - 10 + 'a');
	}
}

int	ft_print_ptr_len(void *ptr)
{
	int	i;

	i = nbr_hex_len((unsigned long long)ptr);
	if (ptr == 0)
	{
		ft_putstr_len("(nil)");
		return (3);
	}
	else
	{
		ft_putstr_len("0x");
		ft_print_ptr((unsigned long long)ptr);
	}
	return (i);
}
