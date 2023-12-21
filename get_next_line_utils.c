/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aheinane <aheinane@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 13:51:09 by aheinane          #+#    #+#             */
/*   Updated: 2023/12/21 19:52:40 by aheinane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "get_next_line.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*d;
	size_t			i;

	d = s;
	i = 0;
	while (i < n)
	{
		d[i] = 0;
		i++;
	}
}

void	*ft_calloc(size_t count, size_t size)
{
	size_t	*c;
	size_t	max;

	max = (size_t)-1;
	if (count > 0 && max / count < size)
		return (NULL);
	c = (size_t *) malloc(count * size);
	if (c == 0)
		return (c);
	ft_bzero (c, count * size);
	return (c);
}
size_t	ft_strlen(char *str )
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strdup(char *src)
{
	size_t	i;
	size_t	j;
	char	*copy;

	i = 0;
	j = 0;
	while (src[j] != '\0')
		j++;
	copy = (char *) malloc((j + 1) * sizeof(char));
	if (!copy)
	{
		//free_function(src);
		return (NULL);
	}
	while (src[i])
	{
		copy[i] = src[i];
		i++;
	}
	copy[i] = '\0';
	return (copy);
}

size_t	ft_strlcpy(char *dst,char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;

	j = 0;
	while (src[j] != '\0')
		j++;
	if (dstsize == 0)
		return (j);
	i = 0;
	while (src[i] != '\0' && (dstsize - 1) > i)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (j);
}

char	*ft_substr(char *s, unsigned int start, size_t len)
{
	char	*p;

	if (!s)
		return (NULL);
	if (start > ft_strlen(s))
		return (ft_strdup(""));
	if (len > ft_strlen(s) - start)
		len = ft_strlen(s) - start;
	p = (char *)malloc(sizeof(char) * (len + 1));
	if (!p)
	{
		// if (s)
		// 	free_function(s);
		return (NULL);
	}
	ft_strlcpy(p, s + start, len + 1);
	return (p);
}

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	i;
	size_t	j;
	char	*new;

	i = 0;
	j = 0;
	if (!s1 || !s2)
		return (NULL);
	new = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!new)
		return (NULL);
	while (s1[i] != '\0')
	{
		new[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
	{
		new[i] = s2[j];
		j++;
		i++;
	}
	new[i] = '\0';
	////free(s1);
	return (new);
}

char	*ft_strchr(char *s, int c)
{
	int i  = 0;
	if (!s)
		return (NULL);
	while (s[i] != '\0')
	{
		if (s[i] == (char)c)
			return ((char *)s);
		i++;
	}
	if ((char)c == 0)
		return ((char *)s);
	return (NULL);
}