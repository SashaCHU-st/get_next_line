#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

char *test(int fd)
{
	int i = 0;
	static char buffer[15];
	read(fd, buffer, 14);
	buffer[i] = '\0';
	while (buffer[i] != '\n')
		{
			printf("%c",buffer[i]);
			i++;
		}
	printf("\n");
	return(buffer);
}

int main ()
{
	int fd;
	fd = open("test_delete.txt", O_RDONLY);
	test(fd);
	test(fd);
	close(fd);
	return (0);
}