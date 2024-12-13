/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cedmarti <cedmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 11:41:40 by cedmarti          #+#    #+#             */
/*   Updated: 2024/11/11 08:26:58 by cedmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <stdio.h>

static size_t	count_words(char const *s, char c)
{
	size_t	i;
	size_t	word;
	size_t	in_word;

	i = 0;
	word = 0;
	in_word = 0;
	while (s[i])
	{
		if (s[i] != c && in_word == 0)
		{
			word++;
			in_word = 1;
		}
		else if (s[i] == c)
			in_word = 0;
		i++;
	}
	return (word);
}

static void	ft_strcopy(char *dest, const char *from, const char *to)
{
	while (from < to)
	{
		*dest = *from;
		dest++;
		from++;
	}
	*dest = '\0';
}

static void	ft_free_tab(char **tab, size_t size)
{
	size_t	i;

	i = 0;
	while (i < size)
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

static int	ft_fill_tab(char **d_tab, const char *s, char c)
{
	const char	*start;
	size_t		i;

	i = 0;
	while (*s)
	{
		if (*s && *s != c)
		{
			start = s;
			while (*s && *s != c)
				s++;
			d_tab[i] = malloc(sizeof(char) * (s - start + 1));
			if (d_tab[i] == NULL)
			{
				ft_free_tab(d_tab, i);
				return (0);
			}
			ft_strcopy(d_tab[i++], start, s);
		}
		else
			s++;
	}
	return (1);
}

char	**ft_split(char const *s, char c)
{
	char		**d_tab;
	size_t		words_count;

	words_count = count_words(s, c);
	d_tab = malloc(sizeof(char *) * (words_count + 1));
	if (d_tab == NULL)
		return (NULL);
	if (ft_fill_tab(d_tab, s, c) == 0)
		return (NULL);
	d_tab[words_count] = NULL;
	return (d_tab);
}

/*int	main(void)
{
	char	**tab;
	char	s[] = "coucou/je/suis cedric";
	char	c = '/';
	int	i;

	i = 0;
	tab = ft_split(s, c);
	while (tab[i] != NULL)
	{
		printf("%s\n", tab[i]);
		i++;
	}
	ft_free_tab(tab, i);
}*/
