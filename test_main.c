#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include "get_next_line.h"



int main (int argc, char **argv)
{
	//char	*line;
	//int		i = 1;
	int		fd;

	fd = open(argv[1], O_RDONLY);

	printf("->%s<-",get_next_line(fd));
	printf("->%s<-\n",get_next_line(fd));
    printf("->%s<-",get_next_line(fd));
    printf("->%s<-\n",get_next_line(fd));
    printf("->%s<-",get_next_line(fd));
    printf("->%s<-\n",get_next_line(fd));

	close(fd);
	return (0);
}
/*
	char *line = get_next_line(fd);
	line =get_next_line(fd);
	 printf("%s",line);
	 free(line);
	printf("%s",line);
	free(line);
	printf("%s",line);
	free(line);
	printf("%s",line);
	free(line);
	printf("%s",line);
	free(line);
	printf("%s",line);
	free(line);

	//line =get_next_line(fd);
	// printf("%s",get_next_line(fd));
	// printf("%s",get_next_line(fd));
	// printf("%s",get_next_line(fd));
	// printf("%s",get_next_line(fd));
	// printf("%s",get_next_line(fd));
	// printf("%s",get_next_line(fd));
 	while ((line = get_next_line(fd)))
	{
	 	printf("%d->%s", i++, line);
	 	free(line);
	 }
	//printf("%s\n", line);
	//get_next_line(fd);
	///	get_next_line(fd);
	close(fd);
	return (0);
}
*/
