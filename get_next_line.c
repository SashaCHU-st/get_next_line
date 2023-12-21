/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aheinane <aheinane@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 13:49:53 by aheinane          #+#    #+#             */
/*   Updated: 2023/12/21 21:18:22 by aheinane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include "get_next_line.h"

char free_function (char **str)
{
	if (!*str)
		return(0);
	free(*str);
	*str = NULL;
	return(0);
}

char	*next_spot(char *storage)
{
	char	*next_spot;
	int		i;
	int		nextspot_index;

	i = 0;
	nextspot_index = 0;
	while (storage[i] && storage[i] != '\n')
		i++;
	if (storage[i] == '\0')
	{
		free_function(&storage);
		return(NULL);
	}
	next_spot = ft_substr(storage, i + 1, ft_strlen(ft_strchr(storage, '\n')));
	if (!next_spot)
	{
		free_function(&storage);
		//free_function(next_spot);
		return (NULL);
	}
	i++;
	while (storage[i])
		next_spot[nextspot_index++] = storage[i++];
	if (!next_spot[0])
	{
		free_function(&storage);
		free_function(&next_spot);
		//free(next_spot);
		return (NULL);
	}
	free (storage);
	return (next_spot);
}

char	*ft_get_line(char *storage)
{
char	*temp;
	int		i;

	i = 0;
	while (storage[i] && storage[i] != '\n')
		i++;
	if (storage[i] != '\n')
		temp = malloc(i + 1);
	else
		temp = malloc(i + 2);
	i = 0;
	if (!temp)
		return (NULL);
	while (storage[i] && storage[i] != '\n')
	{
		temp[i] = storage[i];
		i++;
	}
	if (storage[i] && storage[i] == '\n')
	{
		temp[i] = storage[i];
		i++;
	}
	temp[i] = '\0';
	return (temp);
}

char	*ft_read(int fd, char *storage)
{
	char	buffer[BUFFER_SIZE + 1];
	int		how_many_bytes;
	char	*temp;

	how_many_bytes = 1;
	while (how_many_bytes > 0)
	{
		how_many_bytes = read (fd, buffer, BUFFER_SIZE);
		if (how_many_bytes == -1)
			return (free(storage), NULL);
		else if (how_many_bytes == 0)
			break ;
		buffer[how_many_bytes] = '\0';
		temp = ft_strjoin(storage, buffer);
		if (!temp)
			return (free(storage), NULL);
		free(storage);
		storage = temp;
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	return (storage);
}

char	*get_next_line(int fd)
{
	static char	*storage = NULL;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!storage)
		storage = calloc(1, 1);
	if (!storage)
		return (free(storage), NULL);
	if (!ft_strchr(storage, '\n'))
		storage = ft_read(fd, storage);
	if (!storage || !*storage)
		return (NULL);
	line = ft_get_line(storage);
	// if (!line)
	// 	{
	// 	free_function(storage);
	// 	return (NULL);
	// 	}
	storage = next_spot(storage);
	// if (!line && !storage)
	// {
	// 	free_function(storage);
	// 	return(NULL);
	// }
	return (line);
}