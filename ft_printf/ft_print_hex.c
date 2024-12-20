/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cedmarti <cedmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 08:46:36 by cedmarti          #+#    #+#             */
/*   Updated: 2024/11/19 18:00:47 by cedmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_hex_len(unsigned int num, char c)
{
	int	i;

	i = nbr_hex_len(num);
	if (num >= 16)
	{
		ft_print_hex_len(num / 16, c);
		ft_print_hex_len(num % 16, c);
	}
	else
	{
		if (num < 10)
			ft_putchar_len(num + '0');
		else
		{
			if (c == 'x')
				ft_putchar_len(num - 10 + 'a');
			if (c == 'X')
				ft_putchar_len(num - 10 + 'A');
		}
	}
	return (i);
}
