/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cedmarti <cedmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 11:24:43 by cedmarti          #+#    #+#             */
/*   Updated: 2024/11/07 11:08:25 by cedmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*#include <stdio.h>*/

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;

	i = 0;
	if (dest == NULL && src == NULL)
		return (NULL);
	while (i < n)
	{
		*(unsigned char *)(dest + i) = *(unsigned char *)(src + i);
		i++;
	}
	return (dest);
}

/*void	test_ft_memcpy()
{
	char	string[] = "Hello World!";
	{
		char *s1 = ft_memcpy(string, string + 6, 6);
		printf("Cas 1 - ma fonction : [%s]\n", s1);
		char *s2 = memcpy(string, string + 6, 6);
		printf("Cas 1 - la fonction lib : [%s]\n", s2);
	}
	printf("------------------ \n");
	{
		char *s3 = ft_memcpy(string, string + 6, 3);
		printf("Cas 2 - ma fonction : [%s]\n", s3);
		char *s4 = memcpy(string, string + 6, 3);
		printf("Cas 2 - la fonction lib : [%s]\n", s4);
	}
	printf("------------------ \n");
	{
		char *s5 = ft_memcpy(string, string + 6, 0);
		printf("Cas 3 - ma fonction : [%s]\n", s5);
		char *s6 = memcpy(string, string + 6, 0);
		printf("Cas 3 - la fonction lib : [%s]\n", s6);
	}
	printf("------------------ \n");
	{
		char *s5 = ft_memcpy(NULL, NULL, 0);
		printf("Cas 4 - ma fonction : [%s]\n", s5);
		// char *s6 = memcpy(string, NULL, 0);
		// printf("Cas 4 - la fonction lib : [%s]\n", s6);
	}
}
int	main()
{
	test_ft_memcpy();
	return (0);
}*/
