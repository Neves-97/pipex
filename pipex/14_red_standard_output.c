#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <time.h>
#include <sys/wait.h>
#include <fcntl.h>

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
        // this 0 in 0777 says that it is a octal
        int file = open("pingResults.txt", O_WRONLY | O_CREAT, 0777);
        if (file == -1)
        {
            return 2;
        }
        printf("The fd to pingResults: %d\n", file);
        int file2 = dup2(file, STDOUT_FILENO);
        printf("The duplicated fd: %d\n", file2);
        close(file);

		int err = execlp("ping", "ping", "-c", "3", "movies7.com", NULL);
		if (err == -1)
		{
			printf("Could not find program to execute\n");
			return 2;
		}
	}
	else
	{
		int wstatus;
		// Parent process
		wait(&wstatus);
		if (WIFEXITED(wstatus))
		{
			int statusCode = WEXITSTATUS(wstatus);
			if (statusCode == 0)
			{
				printf("Sucess\n");
			}
			else
			{
				printf("Failure with status code %d\n", statusCode);
			}
		}
		printf("Some post processing goes here!\n");
	}
	
	
	return 0;
}