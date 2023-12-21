#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include "get_next_line.h"



int main ()
{
	char	test[5];
	int		fd;

// 	fd = open("test_delete.txt", O_RDONLY);

// 	printf("%s",get_next_line(fd));
// 	printf("%s",get_next_line(fd));
//     printf("%s",get_next_line(fd));
//     printf("%s",get_next_line(fd));
// 	printf("%s",get_next_line(fd));
//     // printf("%s",get_next_line(fd));
//     // // printf("->%s<-",get_next_line(fd));
//     // // printf("->%s<-\n",get_next_line(fd));
// 	// // printf("->%s<-",get_next_line(fd));
// 	// // printf("->%s<-\n",get_next_line(fd));
//     // // printf("->%s<-",get_next_line(fd));
//     // // printf("->%s<-\n",get_next_line(fd));
//     // // printf("->%s<-",get_next_line(fd));
//     // // printf("->%s<-\n",get_next_line(fd));

char	*line;
	int		i = 1;
	while ((line = get_next_line(fd)))
	{
	 	printf("%d->%s", i++, line);
	 	free(line);
	 }
	// test[0] = 'a';
	// test[1] = 0;
	// printf("%s\n", test);
	// free(test);

// 	close(fd);
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
