/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cedmarti <cedmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 13:56:51 by cedmarti          #+#    #+#             */
/*   Updated: 2024/11/07 10:18:11 by cedmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*#include <stdio.h>*/

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while ((s1[i] || s2[i]) && i < n)
	{
		if ((unsigned char) s1[i] != (unsigned char) s2[i])
			return ((unsigned char) s1[i] - (unsigned char) s2[i]);
		i++;
	}
	return (0);
}

/*void	test_ft_strncmp()
{
	char	s1[] = "coucou";
	char	s2[] = "coudou";
	char	s3[] = "couzou";
	char	s4[] = "couaou";
	char	s5[] = "";

	{
		int i = ft_strncmp(s1, s2, 6);
		printf("Cas 1 - res de ma fonction : [%d]\n", i);
		int j = strncmp(s1, s2, 6);
		printf("Cas 1 - res de le fonction lib : [%d]\n", j);
	}
	printf("------------------ \n");
	{
		int i = ft_strncmp(s3, s4, 6);
		printf("Cas 2 - res de ma fonction : [%d]\n", i);
		int j = strncmp(s3, s4, 6);
		printf("Cas 2 - res de le fonction lib : [%d]\n", j);
	}
	printf("------------------ \n");
	{
		int i = ft_strncmp(s3, s4, 0);
		printf("Cas 3 - res de ma fonction : [%d]\n", i);
		int j = strncmp(s3, s4, 0);
		printf("Cas 3 - res de le fonction lib : [%d]\n", j);
	}
	printf("------------------ \n");
	{
		int i = ft_strncmp(s3, s5, 0);
		printf("Cas 4 - res de ma fonction : [%d]\n", i);
		int j = strncmp(s3, s5, 0);
		printf("Cas 4 - res de le fonction lib : [%d]\n", j);
	}
}
int	main()
{
	test_ft_strncmp();
	return (0);
}*/
