/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cedmarti <cedmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 11:08:46 by cedmarti          #+#    #+#             */
/*   Updated: 2024/12/30 13:31:13 by cedmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "../push_swap.h"

char	*fill_stock(int fd, char *stock, char *buffer)
{
	ssize_t	bytes_read;

	bytes_read = 1;
	if (!stock)
		stock = ft_strdup("");
	while (bytes_read > 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read < 0)
		{
			free(buffer);
			free(stock);
			return (NULL);
		}
		buffer[bytes_read] = 0;
		stock = ft_strjoin(stock, buffer);
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	free(buffer);
	return (stock);
}

char	*extract_line(char *stock, char *line)
{
	int	i;

	i = 0;
	while (stock[i] && stock[i] != '\n')
		i++;
	if (stock[i] == '\n')
		i++;
	line = ft_substr(stock, 0, i);
	return (line);
}

char	*get_new_stock(char *stock)
{
	char	*new_stock;
	int		i;

	i = 0;
	new_stock = NULL;
	while (stock[i] && stock[i] != '\n')
		i++;
	if (stock[i] == '\n')
	{
		i++;
		new_stock = ft_substr(stock, i, ft_strlen(stock) - i);
	}
	free(stock);
	return (new_stock);
}

char	*get_next_line(int fd)
{
	static char	*stock;
	char		*buffer;
	char		*line;

	line = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	stock = fill_stock(fd, stock, buffer);
	if (!stock || stock[0] == '\0')
	{
		free(stock);
		return (stock = NULL);
	}
	line = extract_line(stock, line);
	stock = get_new_stock(stock);
	if (!stock || stock[0] == '\0')
	{
		free(stock);
		stock = NULL;
	}
	return (line);
}
