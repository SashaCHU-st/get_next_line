/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aheinane <aheinane@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 13:49:53 by aheinane          #+#    #+#             */
/*   Updated: 2023/12/19 19:03:54 by aheinane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include "get_next_line.h"

char	*next_spot(char *storage)
{
	char	*next_spot;
	int		i;

	i = 0;
	if (storage[i] == '\0')
		return (free(storage), NULL);
	while (storage[i] && storage[i] != '\n')
		i++;
	next_spot = ft_substr(storage, i + 1, ft_strlen(ft_strchr(storage, '\n')));
	if (!next_spot)
	{
		free (next_spot);
		return (NULL);
	}
	if (!next_spot[0])
	{
		free(storage);
		free(next_spot);
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
	temp = malloc(ft_strlen(storage) + 1);
	if (!temp)
		return (NULL);
	while (storage[i] && storage[i] != '\n')
	{
		temp[i] = storage[i];
		i++;
	}
	if (storage[i] == '\n')
	{
		temp[i] = storage[i];
		i++;
	}
	//	temp[i++] = '\n';
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
		if (how_many_bytes <= 0 && !ft_strchr(buffer, '\n'))
			break ;
		buffer [how_many_bytes] = '\0';
		if (!storage)
			storage = ft_strdup("");
		temp = storage;
		storage = ft_strjoin(storage, buffer);
		free(temp);
		if (!storage)
		{
			free(temp);
			free (buffer);
		}
	}
	//free(buffer);
	return (storage);
}

char	*get_next_line(int fd)
{
	static char	*storage;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	storage = ft_read(fd, storage);
	if (!storage || !*storage)
		return (NULL);
	line = ft_get_line(storage);
	storage = next_spot(storage);
	if (!line && !storage)
	{
		free (storage); 
		storage = NULL; 
	}
	return (line);
}
// int main ()
// {
// 	// char	*line;
// 	//int		i = 1;
// 	int		fd;

// 	fd = open("test_delete.txt", O_RDONLY);
// 	printf("%s",get_next_line(fd));
// 	printf("%s",get_next_line(fd)); 
// 	// printf("%s",get_next_line(fd));
// 	// printf("%s",get_next_line(fd));
// 	// printf("%s",get_next_line(fd));
// 	// printf("%s",get_next_line(fd));

// 	char *line = get_next_line(fd);
// 	line =get_next_line(fd);
// 	 printf("%s",line);
// 	 free(line);
// 	printf("%s",line);
// 	free(line);
// 	printf("%s",line);
// 	free(line);
// 	printf("%s",line);
// 	free(line);
// 	printf("%s",line);
// 	free(line);
// 	printf("%s",line);
// 	free(line);
	
// 	//line =get_next_line(fd);
// 	// printf("%s",get_next_line(fd));
// 	// printf("%s",get_next_line(fd));
// 	// printf("%s",get_next_line(fd));
// 	// printf("%s",get_next_line(fd));
// 	// printf("%s",get_next_line(fd));
// 	// printf("%s",get_next_line(fd));
// 	// 	while ((line = get_next_line(fd)))
// 	// {
// 	// 	printf("%d->%s", i++, line);
// 	// 	free(line);
// 	// }
// 	//printf("%s\n", line);
// 	//get_next_line(fd);
// 	///	get_next_line(fd);
// 	close(fd);
// 	return (0);
// }