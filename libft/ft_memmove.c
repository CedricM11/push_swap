/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cedmarti <cedmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 11:31:33 by cedmarti          #+#    #+#             */
/*   Updated: 2024/11/08 09:58:55 by cedmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// #include <stdio.h>
// #include <assert.h>

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t	i;

	if (!dest && !src)
		return (NULL);
	if (dest < src)
	{
		i = 0;
		while (i < n)
		{
			*(unsigned char *)(dest + i) = *(unsigned char *)(src + i);
			i++;
		}
	}
	else
	{
		i = n - 1 ;
		while ((int)i >= 0)
		{
			*(unsigned char *)(dest + i) = *(unsigned char *)(src + i);
			i--;
		}
	}
	return (dest);
}

// void	test_ft_memmove()
// {
// 	{
// 		char	src[] = "Bonjour";
// 		char	dest[10];

// 		ft_memmove(dest, src, 7);
// 		assert(strcmp(dest, "Bonjour") == 0);
// 		printf("Test 1 passé : Copie sans chevauchement.\n");
// 	}

// 	{
// 		char	buffer[] = "Salut tout le monde";

// 		ft_memmove(buffer + 6, buffer, 5);
// 		assert(strcmp(buffer, "Salut Salutle monde") == 0);
// 		printf("Test 2 passé : Copie avec chevauchement (src avant dest).\n");
// 	}

// 	{
// 		char buffer[] = "Bonjour tout le monde";

// 		ft_memmove(buffer, buffer + 8, 13);
// 		assert(strcmp(buffer, "tout le mondele monde") == 0);
// 		printf("Test 3 passé : Copie avec chevauchement (dest avant src).\n");
//     }

// 	{
// 		char src[] = "Test";
// 		char dest[10] = "Rempli";

// 		ft_memmove(dest, src, 0);
// 		assert(strcmp(dest, "Rempli") == 0);
// 		printf("Test 4 passé : Copie de 0 octet.\n");
// 	}

// 	{
// 		char dest[10] = "Rempli";

// 		ft_memmove(NULL, dest, 5);
// 		ft_memmove(dest, NULL, 5);
// 		printf("Test 5 passé : Cas avec pointeurs NULL.\n");
// 	}
// }

// int main() {
//     test_ft_memmove();
//     printf("Tous les tests sont passés !\n");
//     return 0;
// }
