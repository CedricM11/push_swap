/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cedmarti <cedmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 13:26:58 by cedmarti          #+#    #+#             */
/*   Updated: 2024/11/08 14:00:51 by cedmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*#include <stdio.h>*/

static int	nbr_len(int n)
{
	int	count;

	count = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		count++;
		n = -n;
	}
	while (n > 0)
	{
		count++;
		n = n / 10;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	char	*tab;
	int		len;
	long	nbr;

	nbr = n;
	if (nbr == -2147483648)
		return (ft_strdup("-2147483648"));
	len = nbr_len(n);
	tab = malloc(sizeof(char) * (len + 1));
	if (tab == NULL)
		return (NULL);
	tab[len--] = '\0';
	if (nbr == 0)
		tab[0] = '0';
	if (nbr < 0)
	{
		tab[0] = '-';
		nbr = -nbr;
	}
	while (nbr > 0)
	{
		tab[len--] = (nbr % 10) + '0';
		nbr = nbr / 10;
	}
	return (tab);
}

/*int	main(void)
{
	int	nb = -2147483647;
	printf("%s\n", ft_itoa(nb));
	int	nb2 = -2147483648;
	printf("%s\n", ft_itoa(nb2));
}*/
