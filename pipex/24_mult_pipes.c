#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int ac, char **av)
{
	int fd[3][2];
	int i;

	for (i = 0; i < 3; i++)
	{
		if (pipe(fd[i]) < 0)
		{
			return 1;
		}
	}

	int pid1 = fork()
	if (pid1 < 0)
	{
		return 2;
	}

	if (pid1 == 0)
	{
		//Child process 1
		close(fd[0][1]);
		close(fd[1][0]);
		close(fd[2][0]);
		close(fd[2][1]);
		int x;
		if (read(fd[0][0], &x, sizeof(int)) < 0)
		{
			return 3;
		}
		x += 5;
		if (write(fd[1][1], &x, sizeof(int)) < 0)
		{
			return 4;
		}
	}
	return 0;
}