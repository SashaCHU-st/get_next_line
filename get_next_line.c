/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aheinane <aheinane@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 13:49:53 by aheinane          #+#    #+#             */
/*   Updated: 2023/12/10 10:22:40 by aheinane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

char *get_next_line(int fd)
{
	static char* s;
	char BUFFER_SIZE[100];
	size_t nbytes;
	ssize_t bytes_read;
	int i = 0;

	if (fd < 0 || nbytes <= 0)
		return (NULL);
	nbytes =  sizeof(BUFFER_SIZE);
	bytes_read	 = read(fd ,BUFFER_SIZE, nbytes);
	if (bytes_read < 0)
		return (-1);
	BUFFER_SIZE[nbytes] = '\0';
	while (s != '\n')
	{
		s++;
	}
	s = ft_strjoin(s, BUFFER_SIZE);
	s = malloc (sizeof(s));
	free(s);
}