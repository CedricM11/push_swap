/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cedmarti <cedmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 15:18:03 by cedmarti          #+#    #+#             */
/*   Updated: 2024/11/05 11:22:02 by cedmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	len_little;

	if (little[0] == '\0')
		return ((char *)big);
	i = 0;
	len_little = ft_strlen(little);
	while (big[i] && i < len)
	{
		j = 0;
		while (big[i + j] && little[j] && i + j < len
			&& big[i + j] == little[j])
			j++;
		if (j == len_little)
			return ((char *)big + i);
		i++;
	}
	return (NULL);
}
