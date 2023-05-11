#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <time.h>
#include <sys/wait.h>

// exec functions will replace other fucntions 
// example after exclp printf doesnt appear on console

int main (int ac, char **av)
{
	int pid = fork();
	if (pid == -1)
	{
		return 1;
	}

	if (pid == 0)
	{
		// child process
		execlp("ping", "ping", "-c", "3", "google.com", NULL);
	}
	else
	{
		// Parent process
		wait(NULL);
		printf("Sucess!\n");
		printf("Some post processing goes here!\n");
	}
	
	
	return 0;
}