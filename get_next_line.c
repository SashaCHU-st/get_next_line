/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aheinane <aheinane@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 13:49:53 by aheinane          #+#    #+#             */
/*   Updated: 2023/11/24 16:24:05 by aheinane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

char *get_next_line(int fd)
{
	static char* s;
	char buffer[100];
	size_t nbytes;
	ssize_t bytes_read;
	int i = 0;

	if (fd < 0 || nbytes <= 0)
		return (NULL);
	nbytes=  sizeof(buffer);
	bytes_read	 = read(fd,buffer, nbytes);
	if (bytes_read < 0)
		return (-1);
	buffer[nbytes] = '\0';
	while (s != '\n')
	{
		s++;
	}
	s = ft_strjoin(s, buffer);
	s = malloc (sizeof(s));
	free(s);
}