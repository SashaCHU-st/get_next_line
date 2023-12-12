/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aheinane <aheinane@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 13:49:53 by aheinane          #+#    #+#             */
/*   Updated: 2023/12/11 16:53:06 by aheinane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>
//#include <unistd.h>
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

	new = 0;
	new = malloc(sizeof(new));// malloc mesto dlya novogo stroki
	if (!new)
		return(NULL);
	while (new != '\n')// esli vsrechaet 
	{
		new = read(fd, storage, BUFFER_SIZE);/// chitaet v fd po kol-vu BUFFER_SIZE and store in storage 
		newline = ft_strjoin(newline, storage);
		newline[new]= '\0';
	}
	newline = malloc(sizeof(newline + 1));
	if (!newline)
		return (NULL);
	return (newline);
}

char	*get_next_line(int fd)
{
	static char	*s;
	char		*new;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	//s = malloc(sizeof(BUFFER_SIZE + 1));
	//if (!s)
///return (NULL);
	s = ft_read (fd, s);
	if (s < 0)
		return (NULL);
	while (*s != '\n')
	{
		*s++;
	}
	// s = ft_strjoin(s, BUFFER_SIZE);
	// s = malloc (sizeof(s));
	free(s);
	return(s);
}
int main ()
{
	int fd;
	fd = open("test_delete.txt", O_RDONLY);
	get_next_line(fd);
	get_next_line(fd);
	close(fd);
	return (0);
}