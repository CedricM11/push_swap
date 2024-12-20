/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cedmarti <cedmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 11:50:36 by cedmarti          #+#    #+#             */
/*   Updated: 2024/11/07 09:15:45 by cedmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*#include <stdio.h>*/

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	src_len;
	size_t	dst_len;
	size_t	i;
	size_t	j;

	dst_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	i = 0;
	j = dst_len;
	if (size <= dst_len)
		return (size + src_len);
	while (src[i] && i < size - dst_len - 1)
	{
		dst[j] = src[i];
		i++;
		j++;
	}
	dst[j] = '\0';
	return (dst_len + src_len);
}

/*void	test_ft_strlcat()
{
	char	buffer[20];

	{
		strcpy(buffer, "Hello");
		printf("Cas 1 - Avant : '%s'\n", buffer);
		size_t result = ft_strlcat(buffer, " World", sizeof(buffer));
		printf("Cas 1 - Après : '%s' (Longueur totale : %zu)\n", buffer, result);
	}
	printf("------------------ \n");
	{
		strcpy(buffer, "Hello");
		printf("Cas 2 - Avant : '%s'\n", buffer);
		size_t result = ft_strlcat(buffer, " Universe", 10);
		printf("Cas 2 - Après : '%s' (Longueur totale : %zu)\n", buffer, result);
	}
	printf("------------------ \n");
	{
		strcpy(buffer, "");
		printf("Cas 3 - Avant : '%s'\n", buffer);
		size_t result = ft_strlcat(buffer, "Test", sizeof(buffer));
		printf("Cas 3 - Après : '%s' (Longueur totale : %zu)\n", buffer, result);
	}
	printf("------------------ \n");
	{
		strcpy(buffer, "Hello");
		printf("Cas 4 - Avant : '%s'\n", buffer);
		size_t result = ft_strlcat(buffer, "", sizeof(buffer));
		printf("Cas 4 - Après : '%s' (Longueur totale : %zu)\n", buffer, result);
	}
	printf("------------------ \n");
	{
		strcpy(buffer, "Hello");
		printf("Cas 5 - Avant : '%s'\n", buffer);
		size_t result = ft_strlcat(buffer, " World", 0);
		printf("Cas 5 - Après : '%s' (Longueur totale : %zu)\n", buffer, result);
	}
}

int	main()
{
	test_ft_strlcat();
	return 0;
}*/
