#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

// show that parent and child processes have diferent ids

// int main(int ac, char *av)
// {
// 	int id = fork();
// 	// printf("Hello from id: %d\n", id);
// 	if (id == 0)
// 		printf("Hello from child process\n");
// 	else
// 		printf("Hello from the main process\n");
// 	return (0);
// }

// if we use multiple forks multiplies everysingle time

// int main (int ac, char **av)
// {
// 	fork();
// 	fork();
// 	fork();
// 	fork();
// 	fork();
// 	printf("Hello World\n");
// 	return (0);
// }

// we get hello world 3 times because we only forked the main process that is != then 0
// or else if it was == to 0 it was the child process

int main (int ac, char **av)
{
	int id = fork();
	if (id != 0)
		fork();
	printf("Hello World\n");
	return (0);
}