#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <errno.h>
#include <fcntl.h>

int main (int ac, char **av)
{
	// can create fifo with mkfifo
	if (mkfifo("myfifo1", 0777) == -1)
	{
		if (errno != EEXIST)
		{
			printf("could not create fifo file");
			return 1;
		}
	}

	printf("Opening ...\n");
	int fd = open("myfifo1", O_WRONLY);
	if (fd == -1)
	{
		return 3;
	}
	printf("Opened ...\n");
	int x = 97;
	if (write(fd, &x, sizeof(x)) == -1)
		return 2;
	else
		printf("\n");
	printf("Written\n");
	close(fd);
	printf("closed\n");
	return (0);
}