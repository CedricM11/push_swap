/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cedmarti <cedmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 09:06:46 by cedmarti          #+#    #+#             */
/*   Updated: 2024/11/07 14:27:02 by cedmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*#include <stdio.h>
#include <assert.h>*/

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub_s;
	size_t	i;

	if (!s)
		return (NULL);
	if (start > ft_strlen(s))
		return (ft_strdup(""));
	if (len > ft_strlen(s + start))
		len = ft_strlen(s + start);
	sub_s = malloc(sizeof(char) * (len + 1));
	if (sub_s == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		sub_s[i] = s[start];
		start++;
		i++;
	}
	sub_s[i] = '\0';
	return (sub_s);
}

/*void	test_ft_substr()
{
	char	s[] = "coucou c'est moi";

	{
		char *new = ft_substr(s, 0, 6);
		printf("Cas 1 - res de ma fonction : [%s]\n", new);
		assert(!strcmp(new, "coucou"));
	}
	printf("------------------ \n");
	{
		char *new = ft_substr(s, 0, 60);
		printf("Cas 2 - res de ma fonction : [%s]\n", new);
		assert(!strcmp(new, "coucou c'est moi"));
	}
	printf("------------------ \n");
	{
		char *new = ft_substr(s, 13, 3);
		printf("Cas 3 - res de ma fonction : [%s]\n", new);
		assert(!strcmp(new, "moi"));
	}
}

int	main(void)
{
	test_ft_substr();
	return (0);
}*/
