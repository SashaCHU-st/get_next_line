/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aheinane <aheinane@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 13:49:53 by aheinane          #+#    #+#             */
/*   Updated: 2023/12/13 17:04:37 by aheinane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include "get_next_line.h"

//  nujna function kotoraya chitaet dlinu buffera BUFFER_SIZE=42 (ft_read) 
//i nahodit v nem '\n' pri pomoshi ft_strchr
// vydelayet malloc dlya dliny +1
// esli malloc 0 return 0

//polsle togo kak nashla '\n' kopiruet vse do '\n'
// pri pomoshi strdup v novuuperemenuy line i return(line)

//udalayet ne nujnoe do '\n' pri pomoshi '\n'

// isppolsuya static variable sohranyaetsy gde zakonchilo i 
//soedinyaet so sledyushim string do '\n' ft_strjoin

char	*ft_read(int fd, char *storage)
{
	char	buffer[BUFFER_SIZE + 1];
	int		how_many_bytes = 0;
	while (1)// esli vstrechaet '\n'
	{
		how_many_bytes = read (fd, buffer, BUFFER_SIZE);/// chitaet v fd po kol-vu BUFFER_SIZE and store in storage 
		if (how_many_bytes <= 0)
			break ;
		buffer[how_many_bytes]= '\0';
		storage = ft_strjoin(storage, buffer);
	}
	printf(" storage %s \n", storage);
	return (storage);
}
char *next_spot(storage)
{
	
}

char *get_line(char *storage)
{
	char *temp;
	int i;
	while (!ft_strchr(storage, '\n'))
	{
		temp[i]= storage[i];
		i++;
	}
	return(temp);
}


char	*get_next_line(int fd)
{
	static char	*storage = NULL;
	char 	*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	storage = ft_read(fd, storage);
	if (!storage)
		return (NULL);
	//printf ("storage %s\n", storage);
	line = get_line(storage);
	next_spot(storage);
	//free(storage);
	return(storage);
}
int main ()
{
	int fd;
	fd = open("test_delete.txt", O_RDONLY);
	char *line = get_next_line(fd);
	//printf("%s\n", line);
	//get_next_line(fd);
	///	get_next_line(fd);
	close(fd);
	return (0);
}