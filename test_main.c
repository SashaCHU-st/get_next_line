#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include "get_next_line.h"




	//char	test[5];


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

// int main (int argc, char **argv)
// {
//fd = open(argv[1], O_RDONLY);

//// for not bonus///////////////////////////////////////
int main ()
{
	//////////////////////////////////////////////////////////////////////
	int		fd;

	int		fd;

fd = open("test_delete.txt", O_RDONLY);

char	*line;
	int		i = 1;
	while ((line = get_next_line(fd)))
	{
	 	printf("%d->%s", i++, line);
	 	free(line);
	 }

	close(fd);
	return (0);
}
////////////////////////////////////////////////////////////////////////////////
// FOR BONUS
// 	char	*line;
// 	int		i;
// 	int		fd1;
// 	int		fd2;

// 	fd1 = open("test_delete.txt", O_RDONLY);
// 	fd2 = open("test_delete2.txt", O_RDONLY);
// 	i = 1;
// 	while (1)
// 	{
// 		line = get_next_line(fd1);
// 		if (!line)
//             break;
// 		printf("%d->%s", i++, line);
// 		free(line);
// 		line = get_next_line(fd2);
// 		if (!line)
//             break;
// 		printf("%d->%s", i++, line);
// 		free(line);
// 	}
// 	close(fd1);
// 	close(fd2);
// 	return (0);
// }
//////////////////////////////////////////////////////////////////////////////////
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
