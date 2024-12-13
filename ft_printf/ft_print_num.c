/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_num.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cedmarti <cedmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 08:43:08 by cedmarti          #+#    #+#             */
/*   Updated: 2024/11/11 15:45:04 by cedmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_len(int nb)
{
	int	i;

	i = nbr_len(nb);
	if (nb == -2147483648)
	{
		write(1, "-2147483648", 11);
		return (11);
	}
	if (nb < 0)
	{
		ft_putchar_len('-');
		nb = nb * -1;
	}
	if (nb >= 0 && nb < 10)
		ft_putchar_len(nb + '0');
	else
	{
		ft_putnbr_len(nb / 10);
		ft_putnbr_len(nb % 10);
	}
	return (i);
}

int	ft_u_putnbr_len(unsigned int nb)
{
	unsigned int	i;

	i = 0;
	if (nb < 10)
		i += ft_putchar_len(nb + '0');
	else
	{
		i += ft_u_putnbr_len(nb / 10);
		i += ft_u_putnbr_len(nb % 10);
	}
	return (i);
}
