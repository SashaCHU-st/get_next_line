/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aheinane <aheinane@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 13:52:59 by aheinane          #+#    #+#             */
/*   Updated: 2023/12/12 18:23:13 by aheinane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif
char	*get_next_line(int fd);
char	*ft_read(int fd, char *storage);
size_t	ft_strlen(const char *str );
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strchr(const char *s, int c);


#endif