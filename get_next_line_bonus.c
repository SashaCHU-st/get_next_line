/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aheinane <aheinane@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 13:49:53 by aheinane          #+#    #+#             */
/*   Updated: 2023/12/27 17:32:04 by aheinane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_exist(char *str)
{
	if (!str)
	{
		str = malloc(1);
		if (!str)
			return (0);
		*str = 0;
	}
	return (str);
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
		free(storage);
		return (NULL);
	}
	next_spot = malloc(sizeof(char) * ft_strlen(storage) - i + 1);
	if (!next_spot)
		return (free_function(&storage));
	i++;
	while (storage[i])
		next_spot[nextspot_index++] = storage[i++];
	next_spot[nextspot_index] = '\0';
	free (storage);
	return (next_spot);
}

char	*ft_get_line(char *storage)
{
	char	*temp;
	int		i;

	i = 0;
	if (!storage[i])
		return (NULL);
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
		temp[i++] = '\n';
	temp[i] = '\0';
	return (temp);
}

char	*ft_read(int fd, char *storage)
{
	char	*buffer;
	int		how_many_bytes;

	storage = ft_exist(storage);
	if (!storage)
		return (0);
	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (free_function(&storage));
	how_many_bytes = 1;
	while (how_many_bytes > 0 && !ft_strchr(storage, '\n'))
	{
		how_many_bytes = read (fd, buffer, BUFFER_SIZE);
		if (how_many_bytes == -1)
			return (NULL);
		buffer[how_many_bytes] = '\0';
		storage = ft_strjoin(storage, buffer);
		if (!storage)
			return (free_function(&storage));
	}
	free(buffer);
	return (storage);
}

char	*get_next_line(int fd)
{
	static char	*storage[OPEN_MAX];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read (fd, 0, 0) < 0)
		return (free_function(&storage[fd]));
	storage[fd] = ft_read(fd, storage[fd]);
	if (!storage[fd])
		return (NULL);
	line = ft_get_line(storage[fd]);
	storage[fd] = next_spot(storage[fd]);
	if (!line || !storage[fd])
	{
		free(storage[fd]);
		storage[fd] = NULL;
	}
	return (line);
}
