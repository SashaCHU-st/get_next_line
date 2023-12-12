#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
size_t	ft_strlen(const char *str )
{
	size_t	i;
	size_t	count;

	count = 0;
	i = 0;
	while (str[i] != '\0')
	{
		i++;
		count++;
	}
	return (count);
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
	new = (char *) malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!new)
		return (NULL);
	while (s1[i] != '\0')
	{
		new[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
	{
		new[i + j] = s2[j];
		j++;
	}
	new[i + j] = '\0';
	return (new);
}
char *test(int fd)
{
	static int	i;
	static char	buffer[10];
	char *line = NULL;

	if (buffer[i] == '\n')
		i++;
	if (buffer[i] == '\0')
	{
		read(fd ,buffer ,9);
		buffer[9] = '\0';
		i = 0;
	}
	while (buffer[i] && buffer[i] != '\n')
	{
		printf ("%c",buffer[i]);
		i++;
	}
	line = ft_strjoin(line, buffer);
	printf("\n");
	return (line);
}

int main ()
{
	int fd;
	fd = open("test_delete.txt", O_RDONLY);
	//printf("%s\n",test(fd));
	//printf("%s\n",test(fd));
	test(fd);
	//printf("\n");
	test(fd);
	//printf("\n");
	test(fd);
//	printf("\n");
	test(fd);
//	printf("\n");
	test(fd);
	close(fd);
	return (0);
}