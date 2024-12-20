/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cedmarti <cedmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 13:40:32 by cedmarti          #+#    #+#             */
/*   Updated: 2024/11/08 10:02:16 by cedmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*#include <stdio.h>*/

char	*ft_strrchr(const char *s, int c)
{
	size_t	len;

	len = ft_strlen(s);
	while ((int)len >= 0)
	{
		if (s[len] == (char) c)
			return ((char *)(s + len));
		len--;
	}
	if ((char) c == '\0')
		return ((char *) s);
	return (NULL);
}

/*void	test_ft_strrchr()
{
	char	string[22] = "acoucou je suis cedric";
	{
		char *c = ft_strrchr(string, 'c');
		printf("Cas 1 - res de ma fonction : [%p]\n", c);
		char *s = strrchr(string, 'c');
		printf("Cas 1 - res de la fonction lib : [%p]\n", s);
	}
	printf("------------------ \n");
	{
		char *c = ft_strrchr(string, 'a');
		printf("Cas 2 - res de ma fonction : [%p]\n", c);
		char *s = strrchr(string, 'a');
		printf("Cas 2 - res de la fonction lib : [%p]\n", s);
	}
	printf("------------------ \n");
	{
		char *c = ft_strrchr(string, 'x');
		printf("Cas 3 - res de ma fonction : [%p]\n", c);
		char *s = strrchr(string, 'x');
		printf("Cas 3 - res de la fonction lib : [%p]\n", s);
	}
	printf("------------------ \n");
	{
		char *c = ft_strrchr("", 'c');
		printf("Cas 4 - res de ma fonction : [%p]\n", c);
		char *s = strrchr("", 'c');
		printf("Cas 4 - res de la fonction lib : [%p]\n", s);
	}
}

int	main()
{
	test_ft_strrchr();
	return (0);
}*/
