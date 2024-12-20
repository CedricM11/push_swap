/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cedmarti <cedmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 10:19:39 by cedmarti          #+#    #+#             */
/*   Updated: 2024/11/08 14:02:40 by cedmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <stdio.h>

static int	in_charset(char const *str, char c)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*s2;
	size_t	start;
	size_t	end;
	size_t	i;

	start = 0;
	while (s1[start] && in_charset(set, s1[start]) == 1)
		start++;
	end = ft_strlen(s1);
	if (start == end)
		return (ft_strdup(""));
	while (in_charset(set, s1[end - 1]) == 1)
		end--;
	s2 = malloc(sizeof(char) * (end - start + 1));
	if (s2 == NULL)
		return (NULL);
	i = 0;
	while (start < end)
	{
		s2[i] = s1[start];
		i++;
		start++;
	}
	s2[i] = '\0';
	return (s2);
}

/*int	main(void)
{
	char	s1[] = "  \t \t \n   \n\n\n\t";
	char	s2[] = "";
	char	s3[] = "      coucou  ";
	char	s4[] = "coucou";

	char	*ret1 = ft_strtrim(s3, " ");
	if (strcmp(ret1, s4) == 0)
		printf("SUCCESS\n");
	else
		printf("ERROR\n");

	char	*ret = ft_strtrim(s1, " \n\t");
	if (strcmp(ret, s2) == 0)
		printf("SUCCESS\n");
	else
		printf("ERROR\n");
}*/
