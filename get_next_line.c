/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aheinane <aheinane@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 13:49:53 by aheinane          #+#    #+#             */
/*   Updated: 2023/12/12 18:35:59 by aheinane         ###   ########.fr       */
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
// 

//polsle togo kak nashla '\n' kopiruet vse do '\n'
// pri pomoshi strdup v novuuperemenuy line i return(line)

//udalayet ne nujnoe do '\n' pri pomoshi '\n'

// isppolsuya static variable sohranyaetsy gde zakonchilo i 
//soedinyaet so sledyushim string do '\n' ft_strjoin

char	*ft_read(int fd, char *storage)
{
	int		new;
	char	*newline;
	//static int	i;

	new = 0;
	storage = malloc (BUFFER_SIZE);// malloc mesto dlya novogo stroki
	if (!storage)
		return (NULL);
	while (new > 0 && !ft_strchr(newline, '\n'))// esli vstrechaet '\n'
	{
		new = read (fd, storage, BUFFER_SIZE);/// chitaet v fd po kol-vu BUFFER_SIZE and store in storage 
		storage[new]= '\0';
		newline = ft_strjoin(newline, storage);
		if(!newline)
			break;
	}
	newline = malloc(sizeof(newline + 1));
	// while (newline[i] && newline[i] != '\n')
	// {
	// 	printf ("%c",newline[i]);
	// 	i++;
	// }
	if (!newline)
		return (NULL);	
	return (newline);
}

char	*get_next_line(int fd)
{
	static char	*storage;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	storage = ft_read (fd, storage);
	if (!storage)
		return (NULL);
	//free(storage);
	return(storage);
}
int main ()
{
	int fd;
	fd = open("test_delete.txt", O_RDONLY);
	char *line = get_next_line(fd);
	printf("%s\n", line);
	//get_next_line(fd);
	///	get_next_line(fd);
	close(fd);
	return (0);
}